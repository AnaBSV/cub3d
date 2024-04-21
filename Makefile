NAME= cub3d

INC=/usr/include
SRC_DIR = srcs
INC_DIR = includes
OBJ_DIR = objs
LIBFT_DIR = srcs/libft_v
GNL_DIR = srcs/get_next_line


CC    = cc
CFLAGS = -Wall -Wextra -Werror -g

MLX        = ./minilibx-linux
FLAGS    = $(CFLAGS) -L $(MLX) -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

SRC = $(wildcard $(SRC_DIR)/*.c) \
	  $(wildcard $(LIBFT_DIR)/*.c)\
	  $(wildcard $(GNL_DIR)/*.c)

OBJ := $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
OBJ := $(OBJ:$(LIBFT_DIR)/%.c=$(OBJ_DIR)/%.o)
OBJ := $(OBJ:$(GNL_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(OBJ_DIR):
	mkdir -p ${OBJ_DIR}
	mkdir -p ${OBJ_DIR}/libft_v
	mkdir -p ${OBJ_DIR}/get_next_line

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INC_DIR)

$(OBJ_DIR)/%.o: $(LIBFT_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INC_DIR)

$(OBJ_DIR)/%.o: $(GNL_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INC_DIR)

$(NAME): $(OBJ_DIR) $(OBJ)
		${CC} ${OBJ} ${FLAGS} -o $(NAME)

clean:
	rm -rf $(OBJ)
	rm -rf $(OBJ_DIR)

fclean:        clean
			$(RM) $(NAME)
re: clean all