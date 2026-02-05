NAME = Cub3D
CC = cc

LIB_DIR = ./libft
MLX_DIR = ./minilibx-linux

CFLAGS = -Wall -Werror -Wextra -I./include -I./libft -I$(MLX_DIR)

MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

SRC = gnl/get_next_line_utils.c \
      gnl/get_next_line.c \
      src/main.c \
      src/parser/parser_map.c \
      src/parser/parser_game.c \
      src/parser/parser_info.c \
      src/init/init_game.c \
      src/parser/parser_matrix.c \
      src/parser/parser_check.c \
      src/parser/parser_flood.c \
      src/utils/free_game.c \
      src/parser/parser_verify.c \
      src/utils/utils_colors.c \
      src/graphics/game_start.c \
      src/graphics/game_hooks.c \
      src/graphics/textures.c \
      src/graphics/player_movement.c \
      src/graphics/render.c \
      src/raycast/init_player.c \
      src/raycast/init_camera.c \
      src/raycast/init_ray.c \
      src/raycast/init_steps.c \
      src/raycast/dda_step.c \
      src/raycast/calc_wall_dist.c \
      src/raycast/init_image.c

OBJ = $(SRC:.c=.o)

RM = rm -f

LIBFT = $(LIB_DIR)/libft.a
MLX = $(MLX_DIR)/libmlx.a

all: banner $(LIBFT) $(MLX) $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIB_DIR) >/dev/null 2>&1

$(MLX):
	@$(MAKE) -C $(MLX_DIR) >/dev/null 2>&1

$(NAME): $(OBJ) $(LIBFT) $(MLX)
	@$(CC) $(OBJ) $(LIBFT) $(MLX_FLAGS) -o $(NAME)
	@echo "✅ $(NAME) linked successfully."

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ)
	@$(MAKE) -C $(LIB_DIR) clean >/dev/null 2>&1
	@$(MAKE) -C $(MLX_DIR) clean >/dev/null 2>&1
	@echo "🧹 Object files removed."

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIB_DIR) fclean >/dev/null 2>&1
	@echo "🗑️ Executable and libraries removed."

re: fclean all

.PHONY: all clean fclean re banner

banner:
	@echo "\033[1;36m"
	@echo "                                                                  "
	@echo "          .g8\"\"\"bgd \`7MMF'   \`7MF'\`7MM\"\"\"Yp,         \`7MM\"\"\"Yb.   "
	@echo "        .dP'     \`M   MM       M    MM    Yb           MM    \`Yb. "
	@echo "        dM'       \`   MM       M    MM    dP pd\"\"b.    MM     \`Mb "
	@echo "        MM            MM       M    MM\"\"\"bg.(O)  \`8b   MM      MM "
	@echo "        MM.           MM       M    MM    \`Y      ,89   MM     ,MP "
	@echo "        \`Mb.     ,'   YM.     ,M    MM    ,9    \"\"Yb.   MM    ,dP' "
	@echo "          \`\"bmmmd'     \`bmmmmd\"'  .JMMmmmd9        88 .JMMmmmdP'   "
	@echo "                                             (O)  .M'              "
	@echo "                                              bmmmd'               "
	@echo "                                                                  "
	@echo "\033[0m"
