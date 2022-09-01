NAME = so_long

CC = gcc
CFLAGS = -Wall -Wextra -Werror

LIBFT = -L libft -lft
LIBX = -L mlx_linux -lmlx_Linux
LIBXFLAGS = -lmlx -lXext -lX11

SRCPATH = src/
SRC = action_player.c \
		collisions.c \
		initialize_element.c \
		initialize_list_elements.c \
		initialize.c \
		input_keyboard.c \
		main.c \
		mlx_addresses.c \
		mlx_destroy.c \
		mlx_images.c \
		move_enemy.c \
		move_player.c \
		move.c \
		parsing_map_content.c \
		parsing_map_file.c \
		parsing.c \
		print_elements.c \
		print_land_around_element.c \
		print_land.c \
		print_player.c \
		print_scrolling_bar.c \
		print_utils.c \
		print.c \
		run.c \
		so_long.c \
		utils.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME): $(OBJ)
	$(MAKE) --no-print-directory -C libft
	$(MAKE) --no-print-directory -C mlx_linux
	echo "\033[36mMaking So Long\033[0m"
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(LIBX) $(LIBXFLAGS) -o $(NAME) -g
	echo "\033[32mDone\033[0m"

%.o : $(SRCPATH)%.c
	$(CC) $(CFLAGS) -c $^  -g

bonus : all

clean :
	$(MAKE) --no-print-directory fclean -C libft
	echo "\033[35mCleaning Mlx's objects...\033[0m"
	$(MAKE) --no-print-directory clean -C mlx_linux
	echo "\033[32mDone\033[0m"
	echo "\033[35mCleaning So Long's objects...\033[0m"
	rm -f $(OBJ)
	echo "\033[32mDone\033[0m"

fclean :
	make clean
	echo "\033[35mCleaning So_Long...\033[0m"
	rm -f $(NAME)
	echo "\033[32mDone\033[0m"

re : fclean
	make all

.PHONY : all clean fclean re bonus
.SILENT :