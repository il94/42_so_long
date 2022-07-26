NAME = so_long

CC = gcc
CFLAGS = -Wall -Wextra -Werror

LIBFT = -L libft -lft
LIBX = -L mlx_linux -lmlx_Linux
LIBXFLAGS = -lmlx -lXext -lX11

SRCPATH = src/
SRC = main.c \
		parsing.c \
		images.c \
		print.c \
		so_long.c \
		destroy_elements.c \
		run.c \
		moves.c \
		zoubir.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) --no-print-directory -C libft
	@echo "\033[36mMaking So Long\033[0m"
	@$(CC) $(OBJ) $(LIBFT) $(LIBX) $(LIBXFLAGS) -o $(NAME)
	@echo "\033[32mDone\033[0m"

%.o : $(SRCPATH)%.c
	@$(CC) -c $^

bonus : all

clean :
	@$(MAKE) --no-print-directory fclean -C libft
	@echo "\033[35mCleaning So Long's objects...\033[0m"
	@rm -f $(OBJ)
	@echo "\033[32mDone\033[0m"

fclean : clean
	@echo "\033[35mCleaning So_Long...\033[0m"
	@rm -f $(NAME)
	@echo "\033[32mDone\033[0m"

re : fclean
	@make all

.PHONY : all clean fclean re bonus