SRCS	=	ft_field_char.c ft_field_int.c ft_get_max_square.c ft_reader.c main.c string_functions.c read_std_input.c

OBJS	=	${SRCS:.c=.o}

CC	=	gcc

CFLAGS	=	-Wall -Wextra -Werror

NAME	=	bsq

.c.o:
	${CC} ${CFLAGS} -c $<

all:	${NAME}

${NAME}:	${OBJS}
	${CC} ${CFLAGS} -o ${NAME} ${OBJS}

clean:
	rm -f ${OBJS}

fclean:	clean
	rm -f ${NAME}

re:	fclean all

.PHONY: all clean fclean re

