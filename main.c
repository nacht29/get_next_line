#include "get_next_line.h"

int main(int argc, char *argv[])
{
	int		fd;
	char	*line;

	if (argc < 2)
		return (1);
	fd = open(argv[1], O_RDONLY);

	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	// line = get_next_line(fd);
	// printf("%s\n", line);
	// if (line == NULL)
	// 	printf("NULL\n");
}
