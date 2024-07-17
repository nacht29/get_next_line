#include "get_next_line_bonus.h"

int main(int argc, char *argv[])
{
	int		fd1;
	int		fd2;
	char	*line;
	static char	*line2;

	if (argc < 2)
		return (1);
	fd1 = open(argv[1], O_RDONLY);
	fd2 = open(argv[2], O_RDONLY);

	while (((line = get_next_line(fd1)) != NULL) && ((line2 = get_next_line(fd2)) != NULL))
	{
		printf("1: %s", line);
		free(line);
		printf("2: %s", line2);
		free(line2);
	}

	// line = get_next_line(fd1);
	// printf("%s\n", line);
	// free(line);
	// if (line == NULL)
	// 	printf("NULL\n");
}
