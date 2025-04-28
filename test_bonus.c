#include <fcntl.h>
#include <stdio.h>

#include "get_next_line_bonus.h"

int main()
{
	for (char *line; (line = get_next_line(0));) {
		printf("%s", line);
		free(line);
	}
}
