#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static node	*head;
	char		*line;

	if (fd == 0)
		return (NULL);
	head = (node *)malloc(sizeof(node));
	if (!head)
		return(NULL);
	line = extract_line(&head);
	return (line);
}

void	add_node(node **lst, node *new)
{
	node	*end;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	if (new == NULL)
		return ;
	while ((*lst)->next != NULL)
		(*lst) = (*lst)->next;
	end = (*lst);
	end->next = new;
}

char	*extract_line(node **lst)
{
	node		*current;
	node		*temp;
	static char	*line;

	current = *lst;
	line = ft_strdup("");
	while (current)
	{
		temp = current->next;
		line = ft_strjoin(line, current->str);
		free_node(current);
		current = temp;
	}
	return (line);
}