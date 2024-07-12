#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	counter;

	counter = 0;
	while (s[counter])
		counter++;
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
	return (final_str);
}

int	ft_strchr(const char *s, int c)
{
	char	ref;
	char	*temp;

	ref = (char)c;
	temp = (char *)s;
	while (*temp)
	{
		if (*temp == ref)
			return (TRUE);
		temp++;
	}
	return (FALSE);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*holder;
	size_t	i;
	size_t	strt;

	if (!s)
		return (NULL);
	strt = (size_t)start;
	if (strt > ft_strlen(s))
		return (ft_strjoin("", "")); //use strdup here
	if (len > (ft_strlen(s) - strt + 1))
		holder = malloc(ft_strlen(s) - strt + 2);
	else
		holder = malloc(len + 1);
	if (!holder)
		return (NULL);
	i = 0;
	while (i < len && s[strt + i] != '\0')
	{
		holder[i] = s[strt + i];
		i++;
	}
	holder[len] = '\0';
	return (holder);
}

int	find_newline(node *lst)
{
	while (lst)
	{
		if (ft_strchr(lst->str, '\n'))
			return (TRUE);
		lst = lst->next;
	}
	return (FALSE);
}
