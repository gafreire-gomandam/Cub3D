NAME = CUB3D
CC = cc

CFLAGS = -Wall -Werror -Wextra -I./include -I./libft

SRC = gnl/get_next_line_utils.c \
	  gnl/get_next_line.c \
	  src/main.c \
      src/parser/parser_map.c \
      src/parser/parser_game.c \
	  src/parser/parser_info.c \
	  src/init/init_game.c \
	  src/parser/parser_matrix.c

OBJ = $(SRC:.c=.o)

RM = rm -f

LIB_DIR = ./libft
LIBFT = $(LIB_DIR)/libft.a

all: banner $(LIBFT) $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIB_DIR) >/dev/null 2>&1

$(NAME): $(OBJ) $(LIBFT)
	@$(CC) $(OBJ) $(LIBFT) -o $(NAME) >/dev/null 2>&1
	@echo "✅ $(NAME) linked successfully."

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiling $<..."

clean:
	@$(RM) $(OBJ)
	@$(MAKE) -C $(LIB_DIR) clean >/dev/null 2>&1
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