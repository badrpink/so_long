NAME = so_long.a
LIB = so_long.h ./libft/libft.h get_next_line.h
LIBFT = ./libft/libft.a
SRC = get_next_line.c \
get_next_line_utils.c\
so_long.c\
check_map.c
OBJ = $(SRC:.c=.o)
CC = cc
CFLAGS = -Wall -Werror -Wextra


all: ${NAME} ${LIBFT} so_long.c
	./so_long map.ber
${NAME} : ${OBJ} ${LIBFT}
	ar -rc $@ ${OBJ} $>
	${CC} ${FL``AGS} so_long.c ${NAME} ${LIBFT} -o so_long
${LIBFT}:
	${MAKE} -C ./libft
%.o: %.c ${LIB}
	${CC} ${CFLAGS} -c -o $@ $<
clean:
	rm -f ${OBJ}
	${MAKE} -C ./libft clean
fclean: clean
	rm -f ${NAME} so_long
	${MAKE} -C ./libft fclean
push:
	git add *
	git commit -m "update"
	git push
re: fclean all