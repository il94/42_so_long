NAME = libftgnl.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC = ft_get_next_line.c \
	get_next_line_utils.c \

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	echo "\033[33mMaking Libft_gnl\033[0m"
	ar rcs $(NAME) $^ 
	echo "\033[32mDone\033[0m"

%.o : %.c
	$(CC) $(CFLAGS) -c $^

clean :
	echo "\033[35mCleaning Libft_gnl's objects...\033[0m"
	rm -f $(OBJ)
	echo "\033[32mDone\033[0m"

fclean : clean
	echo "\033[35mCleaning Libft_gnl...\033[0m"
	rm -f $(NAME)
	echo "\033[32mDone\033[0m"

re : fclean all

.PHONY : all clean fclean re
.SILENT :