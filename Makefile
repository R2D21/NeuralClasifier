NAME		=	bin/train

NAME1		=	bin/aff

RM		=	rm -f

CC		=	/usr/bin/gcc

CFLAGS		=	-I /usr/include/ -I includes/ -faggressive-loop-optimizations -W -Wall -Werror -ansi -pedantic -std=gnu99

SRCS		=	e.c \
			src/main.c \

SRC		=	src/train.c \

OBJS		=	$(SRCS:.c=.o)


LIB		=	-lfann -lneurone -L ./lib/bin/ -lre -L /us/lib/

ECHO		=	echo -e

all		:	$(NAME)
$(NAME)		:	$(OBJS)
			make re clean -C lib/
			$(CC)  $(CFLAGS) $(OBJS) -o $(NAME1)  $(LIB)
			@$(ECHO) '\033[0;32m> Compiled\033[0m'
clean	:
			-@$(RM) $(OBJ)
			-@$(RM) *~
			-@$(RM) #*#
			@$(ECHO) '\033[0;35m> Directory cleaned\033[0m'
			$(RM) $(OBJS)
			@$(ECHO) '\033[0;35m> Directory cleaned\033[0m'
aff	:
			$(CC)  $(CFLAGS) $(SRC) -o $(NAME) $(LIB)

fclean		:	$(clean)
			$(RM) $(NAME1)
			@$(ECHO) '\033[0;35m> Remove executable\033[0m'

re		:	fclean all

.PHONY	:	all clean re
