NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror

src =	push_swap.c \
		moves/ft_push.c moves/ft_rotate.c moves/ft_swap.c \
		parcing/input_check.c \
		utils/ft_split_str.c utils/ft_utils_str.c utils/utils_list.c \
		parcing/error.c \

obj = $(src:.c=.o)

all:$(NAME)


$(NAME): $(obj)
	@$(CC) $(CFLAGS) $(obj) -o $(NAME)
clean:
	@rm -fr $(obj)
fclean: clean
	@rm -fr $(NAME)
re: fclean all clean

.SECONDARY : $(obj)
