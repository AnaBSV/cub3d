NAME= cub3d
INC=/usr/include
SRC = ./main.c
OBJ = $(SRC:.c=.o)
CC    = cc
CFLAGS = -Wall -Wextra -Werror

MLX        = ./minilibx-linux
FLAGS    = $(CFLAGS) -L $(MLX) -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

$(NAME):    $(OBJ)
		${CC} ${OBJ} ${FLAGS} -o $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean:        clean
			$(RM) $(NAME)
re: clean all