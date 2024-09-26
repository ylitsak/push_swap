NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra #-Werror -g
INCLUDE = -I ./libft
SRCS = push_swap.c validate_input.c error_handling.c utility_funcs.c linklist_utils.c swap_stack.c push_stack.c \
	rotate_stack.c rev_rotate_stack.c small_sort_algos.c
OBJS = $(SRCS:.c=.o)
LIBFT = ./libft/libft.a

all: $(NAME)

$(LIBFT):
	@$(MAKE) -C ./libft

$(NAME): $(OBJS) $(LIBFT)
	$(CC) -o $(NAME) $(OBJS) $(LIBFT)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	rm -f $(OBJS)
	@$(MAKE) clean -C ./libft

fclean: clean
	rm -f $(NAME) $(LIBFT)

re: fclean all

.PHONY: clean fclean re all