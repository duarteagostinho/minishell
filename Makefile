CC = cc
CFLAGS = -Wall -Werror -Wextra -Ilib -g
SRCS = $(shell find src/ -type f -name '*.c')
OBJS = $(SRCS:.c=.o)
NAME = minishell
LDFLAGS = -lft -L/usr/local/opt/readline/lib -lreadline
LIBFT_DIR = lib/Libft
LIBFT_SRCS =$(shell find $(LIBFT_DIR) -type f -name '*.c')
LIBFT_OBJS = $(LIBFT_SRCS:.c=.o)
LIBFT_LIB = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(LIBFT_LIB): $(LIBFT_OBJS)
	ar rcs $(LIBFT_LIB) $(LIBFT_OBJS)

$(NAME): $(OBJS) $(LIBFT_LIB)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)  $(LDFLAGS) -L$(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

val: re
	valgrind --show-leak-kinds=all --leak-check=full --track-fds=all --suppressions=readline.supp ./minishell

r:
	make re && make clean && clear && ./minishell

.PHONY: all clean fclean re
