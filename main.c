#include "get_next_line.h"

int main(int argc, char* argv[])
{
	char	*line;
	int		fd;
	
	if (argc < 2)
		return (1);
	fd = open(argv[1], O_RDONLY);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s\n", line);
		free(line);
	}
	line = get_next_line(fd);
	if (line == NULL)
		printf("NULL");
	close(fd);
	return (0);
}