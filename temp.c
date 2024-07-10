#include "get_next_line.h"

node	*create_node(const char *str)
{
	node	*new_node;

	new_node = (node *)malloc(sizeof(node));
	if (!new_node)
		return (NULL);
	new_node->str = str;
	new_node->next = NULL;
	return (new_node);
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
		current = temp;
	}
	return (line);
}

void	free_node(node **lst)
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

char	*ft_strdup(const char *src)
{
	int		i;
	char	*holder;

	i = 0;
	holder = malloc(ft_strlen(src) + 1);
	if (!holder)
		return(NULL);
	while (src[i])
	{
		holder[i] = src[i];
		i++;
	}
	holder[i] = '\0';
	return(holder);
}