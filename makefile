NAME = so_long
BNAME = so_long_bonus
LIB = ./mandatory/so_long.h ./get_next_line/get_next_line.h ./ft_printf/ft_printf.h

EX_SRC =./get_next_line/get_next_line.c\
./get_next_line/get_next_line_utils.c\
./ft_printf/ft_printf.c\
./ft_printf/ft_putstr_fd.c\
./ft_printf/ft_strlen.c\
./ft_printf/ft_toupper.c\

SRC = ./mandatory/so_long.c\
./mandatory/check_map.c\
./mandatory/check_path.c\
./mandatory/draw_it.c\
./mandatory/so_long_utils.c\
./mandatory/draw_it_utils.c
BSRC = ./bonus/so_long_bonus.c\
./bonus/check_map_bonus.c\
./bonus/check_path_bonus.c\
./bonus/draw_it_bonus.c\
./bonus/so_long_utils_bonus.c\
./bonus/draw_it_utils_bonus.c\
./bonus/put_str_bonus.c
OBJ = $(SRC:.c=.o)
BOBJ = $(BSRC:.c=.o)
EX_OBJ = $(EX_SRC:.c=.o)
CC = cc
CFLAGS = -Wall -Werror -Wextra 

all: ${NAME}  
	./so_long ./maps/map.ber
${NAME} : ${OBJ} ${EX_OBJ}
	${CC} ${CFLAGS} -lmlx -framework OpenGL -framework AppKit ${OBJ} ${EX_OBJ} -o ${NAME}
${BNAME}: ${BOBJ} ${EX_OBJ}
	${CC} ${CFLAGS} -lmlx -framework OpenGL -framework AppKit ${BOBJ} ${EX_OBJ} -o ${BNAME}

%.o: %.c 
	${CC} ${CFLAGS} -c -o $@ $<
bonus: ${BNAME}
	./so_long_bonus ./maps/map.ber

clean:
	rm -f ${OBJ} ${BOBJ}
fclean: clean
	rm -f ${NAME} ${BNAME}
re: fclean all