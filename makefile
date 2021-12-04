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
ifneq (,$(findstring xterm,${TERM}))
	BLACK        := $(shell tput -Txterm setaf 0)
	RED          := $(shell tput -Txterm setaf 1)
	GREEN        := $(shell tput -Txterm setaf 2)
	YELLOW       := $(shell tput -Txterm setaf 3)
	LIGHTPURPLE  := $(shell tput -Txterm setaf 4)
	PURPLE       := $(shell tput -Txterm setaf 5)
	BLUE         := $(shell tput -Txterm setaf 6)
	WHITE        := $(shell tput -Txterm setaf 7)
	RESET := $(shell tput -Txterm sgr0)
else
	BLACK        := ""
	RED          := ""
	GREEN        := ""
	YELLOW       := ""
	LIGHTPURPLE  := ""
	PURPLE       := ""
	BLUE         := ""
	WHITE        := ""
	RESET        := ""
endif
TITLE="\n $(BLUE)██████  ███████ ███    ██ ██████  ██    ██\n"\
	"$(BLUE)██   ██ ██      ████   ██ ██   ██ ██    ██\n"\
	"$(BLUE)██████  █████   ██ ██  ██ ██   ██ ██    ██\n"\
	"$(BLUE)██      ██      ██  ██ ██ ██   ██ ██    ██\n"\
	"$(BLUE)██      ███████ ██   ████ ██████   ██████ \n"\
	"\n\n $(PURPLE)ᐅ $(YELLOW)Making something like $(GREEN)$(NAME) $(YELLOW)or a shitty thing $(RED)(╯°□°)╯︵ ┻━┻ $(RESET)\n\n"

.SILENT:

all : $(NAME)

$(NAME) : title
	$(CC) $(SRCS) $(CFLAGS) -o $@

fclean :
	rm pendu
clean :
	rm pendu
re : fclean $(NAME)

title:clear
	echo $(TITLE)

clear:
	clear
