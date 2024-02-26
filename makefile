NAME = so_long.
LIB = so_long.h ./libft/libft.h ./get_next_line/get_next_line.h
LIBFT = ./libft/libft.a
SRC = get_next_line.c get_next_line_utils.c so_long.c
OBJ = $(SRC:.c=.o)
CC = cc
FLAGS = -Wall -Werror -Wextra

all: ${NAME} ${LIBFT} so_long
	${CC} ${FLAGS} ${NAME} -o so_long
${NAME} : ${OBJ} ${LIBFT} 
	ar -rc $@ ${OBJ} ${LIBFT}
${LIBFT}:
	${MAKE} -C ./libft
%.o: %.c ${LIB}
	${CC} ${FLAGS} -c -o $@ $^
clean:
	rm -f ${OBJ}
	${MAKE} -C ./libft clean
fclean: clean
	rm -f ${NAME} so_long
	${MAKE} -C ./libft fclean
re: fclean all
