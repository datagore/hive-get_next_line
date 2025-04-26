#include <fcntl.h>
#include <stdio.h>

#include "get_next_line.h"

int main()
{
	int line_number = 1;
	int file = open("Makefile", O_RDONLY);
	for (char *line; (line = get_next_line(file));) {
		printf("%02d %s", line_number++, line);
		free(line);
	}
	close(file);
}
