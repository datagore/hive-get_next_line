NAME	:= test
SOURCES := test.c get_next_line.c
HEADERS := get_next_line.h
CFLAGS  := -Wall -Wextra -Werror -g \
		   -fsanitize=address -fsanitize=leak -fsanitize=undefined

$(NAME): $(SOURCES) $(HEADERS)
	$(CC) $(SOURCES) -o $@ $(CFLAGS)

clean:
	$(RM) $(NAME)

.PHONY: clean
