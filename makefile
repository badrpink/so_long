NAME = so_long
BNAME = so_long_bonus
LIB = ./mandatory/so_long.h ./get_next_line/get_next_line.h ./ft_printf/ft_printf.h
SRC = ./get_next_line/get_next_line.c\
./get_next_line/get_next_line_utils.c\
./ft_printf/ft_printf.c\
./ft_printf/ft_putstr_fd.c\
./ft_printf/ft_strlen.c\
./ft_printf/ft_toupper.c\
./mandatory/so_long.c\
./mandatory/check_map.c\
./mandatory/check_path.c\
./mandatory/draw_it.c\
./mandatory/so_long_utils.c\
./mandatory/draw_it_utils.c
OBJ = $(SRC:.c=.o)
BSRC = ./bonus/so_long_bonus.c\
./bonus/check_map_bonus.c\
./bonus/check_path_bonus.c\
./bonus/draw_it_bonus.c\
./bonus/so_long_utils_bonus.c\
./bonus/draw_it_utils_bonus.c
BOBJ = $(BSRC:.c=.o)
CC = cc
CFLAGS = -Wall -Werror -Wextra 

all: ${NAME}  
	./so_long ./maps/map.ber
${NAME} : ${OBJ}
	${CC} ${CFLAGS} -lmlx -framework OpenGL -framework AppKit ${OBJ}  -o ${NAME}

%.o: %.c ${LIB}
	${CC} ${CFLAGS} -c -o $@ $<
bonus: ${BNAME}

${BNAME}: ${BOBJ}
	${CC} ${CFLAGS} -lmlx -framework OpenGL -framework AppKit ${BOBJ}  -o ${BNAME}
%_bonus.o: %_bonus.c so_long_bonus.h
	${CC} ${CFLAGS} -c -o $@ $<
clean:
	rm -f ${OBJ}
fclean: clean
	rm -f ${NAME} so_long

re: fclean all