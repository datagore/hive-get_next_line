SOURCES := test.c get_next_line.c get_next_line_utils.c
HEADERS := get_next_line.h
BONUS_SOURCES := test.c get_next_line_bonus.c get_next_line_utils_bonus.c
BONUS_HEADERS := get_next_line_bonus.h
CFLAGS  := -Wall -Wextra -Werror -ggdb

all: mandatory bonus

mandatory: $(SOURCES) $(HEADERS)
	$(CC) $(SOURCES) -o $@ $(CFLAGS)

bonus: $(BONUS_SOURCES) $(BONUS_HEADERS)
	$(CC) $(BONUS_SOURCES) -o $@ $(CFLAGS)

clean:
	$(RM) mandatory bonus

re: clean all

.PHONY: all clean re
