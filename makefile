NAME = so_long.a
LIB = so_long.h ./libft/libft.h get_next_line.h
SRC = get_next_line.c \
get_next_line_utils.c\
so_long.c\
check_map.c\
check_path.c\
draw_it.c
OBJ = $(SRC:.c=.o)
CC = cc
CFLAGS = -Wall -Werror -Wextra 

all: ${NAME}  so_long.c
	./so_long map.ber
${NAME} : ${OBJ} 
	ar -rc $@ ${OBJ} 
	${CC} ${CFLAGS} -lmlx -framework OpenGL -framework AppKit ${NAME}  -o so_long
%.o: %.c ${LIB}
	${CC} ${CFLAGS} -lmlx -framework OpenGL -framework -c -o $@ $<
clean:
	rm -f ${OBJ}
fclean: clean
	rm -f ${NAME} so_long

re: fclean all