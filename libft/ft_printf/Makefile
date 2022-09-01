NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c \
	convert_flag.c \
	p_convert_flag.c \
	flags.c
OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	echo "\033[33mMaking Libft_printf\033[0m"
	ar rcs $(NAME) $^ 
	echo "\033[32mDone\033[0m"

%.o : %.c
	$(CC) $(CFLAGS) -c $^

clean :
	echo "\033[35mCleaning Libft_printf's objects...\033[0m"
	rm -f $(OBJ)
	echo "\033[32mDone\033[0m"

fclean : clean
	echo "\033[35mCleaning Libft_printf...\033[0m"
	rm -f $(NAME)
	echo "\033[32mDone\033[0m"

re : fclean all

.PHONY : all clean fclean re
.SILENT :