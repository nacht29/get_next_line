#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static node	*lst;
	node		*current_node;
	node		*temp_node;
	char		*temp_buff;
	char		*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &next_line, 0) < 0)
		return (NULL);
	temp_buff = NULL;
	read_to_list(&lst, fd);
	if (lst == NULL)
		return (NULL);
	next_line = extract_line(lst, &temp_buff);
	current_node = lst;
	while (current_node)
	{
		temp_node = current_node->next;
		free(current_node->str);
		free(current_node);
		current_node = temp_node;
	}
	lst = NULL;
	if (temp_buff != NULL)
		add_node(&lst, temp_buff);
	return (next_line);
}

void	read_to_list(node **lst, int fd)
{
	int		char_read;
	char	*buffer;

	char_read = 0;
	while (find_newline(*lst) == FALSE)
	{
		buffer = malloc(BUFFER_SIZE + 1);
		char_read = read(fd, buffer, BUFFER_SIZE);
		if (char_read <= 0)
		{
			free(buffer);
			return ;
		}
		buffer[char_read] = '\0';
		add_node(lst, buffer);
		free(buffer);
	}
}

void	add_node(node **lst, char *buffer)
{
	node	*new_node;
	node	*end;

	new_node = (node *)malloc(sizeof(node));
	if (!new_node)
		return ;
	new_node->str = ft_strjoin("", buffer);
	new_node->next = NULL;
	end = *lst;
	if (end == NULL)
	{
		*lst = new_node;
		return ;
	}
	while (end->next != NULL)
		end = end->next;
	end->next = new_node;
}

char *extract_line(node *lst, char **temp_buff)
{
	char *line;
	char *temp;
	size_t i;

	line = malloc(1);
	line[0] = '\0';
	while (lst)
	{
		if (ft_strchr(lst->str, '\n') == FALSE)
		{
			temp = ft_strjoin(line, lst->str);
			free(line);
			line = temp;
		}
		else
		{
			i = 0;
			while (lst->str[i] != '\n')
				i++;
			temp = ft_substr(lst->str, 0, i + 1);
			char *new_line = ft_strjoin(line, temp);
			free(line);
			free(temp);
			line = new_line;
			if ((lst->str)[i + 1] != '\0')
				*temp_buff = ft_substr(lst->str, (i + 1), (ft_strlen(lst->str) - (i + 1)));
			return (line);
		}
		lst = lst->next;
	}
	return (line);
}
