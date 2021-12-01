CC=gcc
CFLAGS = -Werror -Wall -Wextra
NAME=pendu
SRCS=src/check_flag.c\
		src/dict.c\
		src/game.c\
		src/main.c\
		src/man.c\
		src/put_things.c\
		src/tools.c\
		src/tools2.c\
		src/verifications.c\
		src/ft_printf.a
all : fclean $(NAME)

$(NAME) :
	$(CC) $(SRCS) $(CFLAGS) -o $@

fclean :
	rm pendu
clean :
	rm pendu
re : fclean $(NAME)
