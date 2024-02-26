NAME = so_long.a
LIB = so_long.h ./libft/libft.h ./get_next_line/get_next_line.h
SRC = ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c so_long.c
OBJ = {$(src:.c=.o)}
CC = cc
FLAGS = -Wall -Werror -Wextra

all: ${NAME}

${NAME} : ${obj}
	ar -rc $@ $^
%.o: %.c ${LIB}
	${CC} ${FLAGS} -c -o $@ $<
clean:
	rm -f ${obj}
fclean: clean
	rm -f ${NAME}
re: fclean all
