NAME = so_long

CC = gcc
CFLAGS = -Wall -Wextra -Werror

LIBFT = -L libft -lft
LIBX = -L mlx_linux -lmlx_Linux
LIBXFLAGS = -lmlx -lXext -lX11

SRCPATH = src/
SRC = main.c \
		parsing.c \
		parsing_map_content.c \
		parsing_map_file.c \
		mlx_images.c \
		mlx_addresses.c \
		mlx_destroy.c \
		print.c \
		print_elements.c \
		print_utils.c \
		print_utils2.c \
		print_scrolling_bar.c \
		print_player.c \
		so_long.c \
		run.c \
		move.c \
		move_player.c \
		move_enemy.c \
		read_map.c \
		zoubir.c \
		collisions.c \
		initialize.c \
		initialize_elements.c \
		action_player.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) --no-print-directory -C libft
	@$(MAKE) --no-print-directory -C mlx_linux
	@echo "\033[36mMaking So Long\033[0m"
	@$(CC) $(OBJ) $(LIBFT) $(LIBX) $(LIBXFLAGS) -o $(NAME) -g3
	@echo "\033[32mDone\033[0m"

%.o : $(SRCPATH)%.c
	@$(CC) -c $^ -g3

bonus : all

clean :
	@$(MAKE) --no-print-directory fclean -C libft
	@echo "\033[35mCleaning Mlx's objects...\033[0m"
	@$(MAKE) --no-print-directory clean -C mlx_linux
	@echo "\033[32mDone\033[0m"
	@echo "\033[35mCleaning So Long's objects...\033[0m"
	@rm -f $(OBJ)
	@echo "\033[32mDone\033[0m"

fclean :
	@make clean
	@echo "\033[35mCleaning So_Long...\033[0m"
	@rm -f $(NAME)
	@echo "\033[32mDone\033[0m"

re : fclean
	@make all

.PHONY : all clean fclean re bonus