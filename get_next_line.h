#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <stdio.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20
# endif

# define TRUE 1
# define FALSE 0

typedef struct s_linked_list
{
	char					*str;
	struct s_linked_list	*next;
}	t_node;

char	*get_next_line(int fd);
int		read_to_list(t_node **lst, int fd);
void	add_node(t_node **lst, char *buffer);
char	*extract_line(t_node *lst, char **temp_buff);
void	free_list(t_node **lst);

size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strchr(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	free_list(t_node **lst);
#endif