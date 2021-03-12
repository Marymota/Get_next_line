NAME = get_next_line.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address
LIB = get_next_line.h
LIBOPT = ar rcs
SRC = get_next_line.c
OBJS = $(SRC:.c=.o)

all:		$(NAME)

$(NAME): 	$(OBJS)
			$(LIBOPT) $@ $^

clean:
		rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)

re:		fclean all

.PHONY: all clean fclean re


