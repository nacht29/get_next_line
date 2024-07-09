#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static node	*head;

	head = (node *)malloc(sizeof(node));
	return (NULL);
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
