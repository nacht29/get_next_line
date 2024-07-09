#include "get_next_line.h"
#include <stdio.h>

int main(void)
{
	char *line = ft_strdup("");

	line = ft_strjoin(line, "hi\n");
	write(1, line, 5);
}