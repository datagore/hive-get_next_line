#include <fcntl.h>
#include <stdio.h>

#include "get_next_line.h"

int main(int argc, char **argv)
{
	int file = 0;
	if (argc == 2)
		file = open(argv[1], O_RDONLY);
	for (;;) {
		char *line = get_next_line(file);
		if (line == NULL)
			break;
		printf("%s", line);
		free(line);
	}
	close(file);
}
