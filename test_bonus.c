#include <fcntl.h>
#include <stdio.h>
#include <string.h>

#include "get_next_line.h"

int main(int argc, char **argv)
{
	// Open all files passed on the command line.
	int file_count = argc - 1;
	int files[file_count + 1];
	if (argc > 1) {
		for (int i = 0; i < file_count; i++)
			files[i] = open(argv[i + 1], O_RDONLY);

	// Use stdin if no files were passed.
	} else {
		files[0] = 0;
		file_count = 1;
	}

	// Keep track of how many files are finished.
	int finished_count = 0;
	char finished[file_count];
	memset(finished, 0, sizeof(finished));

	// Cycle between active files.
	for (int i = 0; finished_count < file_count; i = (i + 1) % file_count) {
		if (!finished[i]) {
			char *line = get_next_line(files[i]);
			if (line == NULL) {
				finished[i] = 1;
				finished_count++;
			} else {
				printf("%s", line);
				free(line);
			}
		}
	}
}
