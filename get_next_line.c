#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static node	*lst;
	char		*temp_buff;
	char		*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &next_line, 0) < 0)
		return (NULL);
	lst = NULL;
	temp_buff = NULL;
	if (read_to_list(&lst, fd) == FALSE)
		return (NULL);
	next_line = extract_line(lst, &temp_buff);
	/*
	static node	*temp;
	temp = lst;
	while (temp != NULL)
	{
		printf("%s", temp->str);
		temp = temp->next;
	}
	*/
	free_list(&lst);
	if (temp_buff != NULL)
		add_node(&lst, temp_buff);
	return (next_line);
}

int	read_to_list(node **lst, int fd)
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
			return (FALSE);
		}
		buffer[char_read] = '\0';
		add_node(lst, buffer);
	}
	return (TRUE);
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

char	*extract_line(node *lst, char **temp_buff)
{
	char	*line;
	size_t	i;

	line = ft_strjoin("","");
	while (lst)
	{
		if (ft_strchr(lst->str, '\n') == FALSE)
			line = ft_strjoin(line, lst->str);
		else
		{
			i = 0;
			while (lst->str[i] != '\n')
				i++;
			line = ft_strjoin(line, ft_substr(lst->str, 0, i + 1));
			*temp_buff = ft_substr(lst->str, (i + 1), (ft_strlen(lst->str) - i - 1));
		}
		lst = lst->next;
	}
	return (line);
}

void	free_list(node **lst)
{
	node *temp;
	node *current;

	if (!lst || !(*lst))
		return ;
	current = *lst;
	while (current)
	{
		temp = current->next;
		free(current->str);
		free(current);
		current = temp;
	}
	(*lst) = NULL;
}