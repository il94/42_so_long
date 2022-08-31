NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC = ft_atoi.c \
	ft_bzero.c \
	ft_calloc.c \
	ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_isprint.c \
	ft_itoa.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_memset.c \
	ft_putchar_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_putstr_fd.c \
	ft_split.c \
	ft_strchr.c \
	ft_strdup.c \
	ft_striteri.c \
	ft_strjoin.c \
	ft_strlcat.c \
	ft_strlcpy.c \
	ft_strlen.c \
	ft_strmapi.c \
	ft_strncmp.c \
	ft_strnstr.c \
	ft_strrchr.c \
	ft_strtrim.c \
	ft_substr.c \
	ft_tolower.c \
	ft_toupper.c \
	ft_lstnew.c \
	ft_lstadd_front.c \
	ft_lstsize.c \
	ft_lstlast.c \
	ft_lstadd_back.c\
	ft_lstdelone.c \
	ft_lstclear.c \
	ft_lstiter.c \
	ft_lstmap.c	\
	ft_long_long_atoi.c \
	ft_delete_content.c \
	ft_print_array.c \
	ft_get_size_array.c \
	ft_free_array.c \
	ft_print_bits.c \
	ft_iswhitespace.c \
	ft_islower.c \
	ft_get_size_number.c \
	ft_get_file_content.c

OBJ = $(SRC:.c=.o)

ADD_SRC = #Ajouter les fichiers specifiques au projet en cours\

ADD_OBJ = $(ADD_SRC:.c=.o)

LIBFT_BASE = libft_base.a
PRINTF = ft_printf/libftprintf.a
GNL = ft_get_next_line/libftgnl.a

all : $(NAME)

$(NAME) : $(OBJ) $(ADD_OBJ)
	@$(MAKE) --no-print-directory -C ft_printf
	@$(MAKE) --no-print-directory -C ft_get_next_line
	@echo "\033[33mMaking Libft\033[0m"
	@ar rc $(LIBFT_BASE) $^
	@ar -rcT $(NAME) $(LIBFT_BASE) $(PRINTF) $(GNL)
	@echo "\033[32mDone\033[0m"

%.o : %.c
	@$(CC) $(CFLAGS) -c $^

clean :
	@$(MAKE) --no-print-directory fclean -C ft_printf
	@$(MAKE) --no-print-directory fclean -C ft_get_next_line
	@echo "\033[35mCleaning Libft's objects...\033[0m"
	@rm -f $(OBJ) $(ADD_OBJ)
	@echo "\033[32mDone\033[0m"

fclean : clean
	@echo "\033[35mCleaning Libft...\033[0m"
	@rm -f $(LIBFT_BASE)
	@rm -f $(NAME)
	@echo "\033[32mDone\033[0m"

re : fclean all

.PHONY : all clean fclean re