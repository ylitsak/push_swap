NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDE = -I ./libft
SRCS = push_swap.c validate_input.c error_handling.c utility_funcs.c
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