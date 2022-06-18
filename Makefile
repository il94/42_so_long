NAME = so_long

CC = gcc
CFLAGS = -Wall -Wextra -Werror

LIBFT = -L libft -lft

LIBX = -L mlx_linux -lmlx_Linux
LIBXFLAGS = -lmlx -lXext -lX11

SRCPATH = src/
SRC = main.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C libft
	$(CC) $(OBJ) $(LIBFT) $(LIBX) $(LIBXFLAGS) -o $(NAME)

%.o: %.c
	$(CC) -c $^

clean :
	$(MAKE) clean -C libft
	rm -f $(OBJ)

fclean : clean
	rm libft/libft.a
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re