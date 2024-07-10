#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static node	*lst;
	char		*next_line;
	char		*temp_buff;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &next_line, 0) < 0)
		return (NULL); 
	lst = NULL;
	temp_buff = NULL;
	read_to_list(lst, fd);
	// next_line = extract_line(lst, &temp_buff);
	// free_list(&list);
	if (temp_buff != NULL)
		add_node(&lst, temp_buff);
	return (next_line);
}

static void	read_to_list(node *lst, int fd)
{
	int		char_read;
	char	*buffer;

	while (find_newline(*lst) == FALSE)
	{
		buffer = malloc(BUFFER_SIZE + 1);
		char_read = read(fd, buffer, BUFFER_SIZE);
		if (!char_read)
		{
			free(buffer);
			return ;
		}
		buffer[char_read] = '\0';
		add_node(lst, buffer);
	}
}

static void	add_node(node **lst, char *buffer)
{
	node	*new_node;
	node	*end;

	new_node = (node *)malloc(sizeof(node));
	if (!new_node)
		return (NULL);
	new_node->str = buffer;
	new_node->next = NULL;
	end = lst;
	if (*lst == NULL)
	{
		*lst = new_node;
		return ;
	}
	end = *lst;
	while (end->next != NULL)
		end = end->next;
	end->next = new_node;
}

char	*extract_line(node *lst, char **temp_buff)
{
	;
}