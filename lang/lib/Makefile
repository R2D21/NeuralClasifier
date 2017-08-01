NAME	=	bin/libneurone.a

RM	=	rm -f

CC	=	gcc

CFLAGS	=	-I ../includes -I includes -g3 -ggdb -W -Wall -Werror -ansi -pedantic -std=gnu99

SRCS	=	src/func.c \
		src/get_next_line.c \
		src/scraping.c \

OBJS	=	$(SRCS:.c=.o)

ECHO	=	echo -e

all	:	$(NAME)

$(NAME)	:	$(OBJS)

		ar r $(NAME) $(OBJS)
		ranlib $(NAME)

clean	:

		$(RM) $(OBJS)

fclean	:	$(clean)
		$(RM) $(NAME)

re	:	fclean all

.PHONY	: all clean fclean re
