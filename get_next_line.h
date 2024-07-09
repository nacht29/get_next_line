#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>

# define BUFFER_SIZE 20

typedef struct linked_list
{
	const char			*str;
	struct link_list	*next;
}	node;

char	*get_next_line(int fd);
void	add_node(node **lst, node *new);
char	*extract_line(node **lst);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *src);
node	*create_node(const char *str);
void	free_node(node **lst);
#endif