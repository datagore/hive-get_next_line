SOURCES := get_next_line.c get_next_line_utils.c
HEADERS := get_next_line.h
BONUS_SOURCES := get_next_line_bonus.c get_next_line_utils_bonus.c
BONUS_HEADERS := get_next_line_bonus.h
CFLAGS  := -Wall -Wextra -Werror -ggdb \
# -fsanitize=address -fsanitize=leak -fsanitize=undefined \

all: mandatory bonus mix

mandatory: test.c $(SOURCES) $(HEADERS)
	$(CC) test.c $(SOURCES) -o $@ $(CFLAGS)

bonus: test.c $(BONUS_SOURCES) $(BONUS_HEADERS)
	$(CC) test.c $(BONUS_SOURCES) -o $@ $(CFLAGS)

mix: mix.c $(BONUS_SOURCES) $(BONUS_HEADERS)
	$(CC) mix.c $(BONUS_SOURCES) -o $@ $(CFLAGS)

clean:
	$(RM) mandatory bonus mix

re: clean all

.PHONY: all clean re
