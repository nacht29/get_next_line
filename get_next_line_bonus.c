#include "get_next_line_bonus.h"

char    *get_next_line(int fd)
{
	static node	*lst[OP];
	char		*temp_buff[OP];
	char		*next_line;
	int			read_result;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &next_line, 0) < 0)
		return (NULL);
	temp_buff[fd] = NULL;
	read_result = read_to_list(&lst[fd], fd);
	if (read_result < 0 || (read_result == 0 && lst[fd] == NULL))
		return (NULL);
	next_line = extract_line(lst[fd], &temp_buff[fd]);
	free_list(&lst[fd]);
	if (temp_buff[fd] != NULL)
	{
		add_node(&lst[fd], temp_buff[fd]);
		free(temp_buff[fd]);
	}
	return (next_line);
}

int read_to_list(node **lst, int fd)
{
	int		char_read;
	char	*buffer;
	node	*current;

	while (1)
	{
		current = *lst;
		while (current)
		{
			if (ft_strchr(current->str, '\n'))
				return (1);
			current = current->next;
		}
		buffer = malloc(BUFFER_SIZE + 1);
		char_read = read(fd, buffer, BUFFER_SIZE);
		if (char_read <= 0)
		{
			free(buffer);
			return (char_read);
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

static char	*process_newline_node(node *lst, char **temp_buff, char *line)
{
	size_t	i;
	char	*temp;
	char	*new_line;

	i = 0;
	while (lst->str[i] != '\n')
		i++;
	temp = ft_substr(lst->str, 0, i + 1);
	new_line = ft_strjoin(line, temp);
	free(line);
	free(temp);
	if ((lst->str)[i + 1] != '\0')
		*temp_buff = ft_substr(lst->str, (i + 1), (ft_strlen(lst->str) - (i + 1)));
	return (new_line);
}

char	*extract_line(node *lst, char **temp_buff)
{
	char	*line;
	char	*temp;

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
			line = process_newline_node(lst, temp_buff, line);
			return (line);
		}
		lst = lst->next;
	}
	return (line);
}