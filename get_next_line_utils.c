#include "get_next_line.h"
#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	counter;

	counter = 0;
	while (s[counter])
	{
		counter++;
	}
	return(counter);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	total_size;
	char	*final_str;
	char	*holder;

	if (!s1 || !s2)
		return(NULL);
	total_size = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	holder = malloc(total_size + 1);
	if (!holder)
		return(NULL);
	final_str = holder;
	while (*s1)
	{
		*holder = *s1;
		holder++;
		s1++;
	}
	while (*s2)
	{
		*holder = *s2;
		holder++;
		s2++;
	}
	*holder = '\0';
	return(final_str);
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

node	*create_node(const char *str)
{
	node	*new_node = (node *)malloc(sizeof(node));
	if (!new_node)
		return(NULL);
	new_node->str = ft_strdup(str);
	if (!new_node->str)
	{
		free(new_node);
		return(NULL);
	}
	new_node->next = NULL;
	return(new_node);
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
