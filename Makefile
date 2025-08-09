# Variables
CC = gcc
CFLAGS = -Wall -Werror -Wextra -Ilib -g
SRCS =$(shell find src/ -type f -name '*.c')
OBJS = $(SRCS:.c=.o)
NAME = minishell
LDFLAGS = -lft -L/usr/local/opt/readline/lib -lreadline

# Libft variables
LIBFT_DIR = lib/libft
LIBFT_SRCS =$(shell find $(LIBFT_DIR) -type f -name '*.c')
LIBFT_OBJS = $(LIBFT_SRCS:.c=.o)
LIBFT_LIB = $(LIBFT_DIR)/libft.a

# Rules
all: $(NAME)

$(LIBFT_LIB): $(LIBFT_OBJS)
	@ar rcs $(LIBFT_LIB) $(LIBFT_OBJS)

$(NAME): $(OBJS) $(LIBFT_LIB)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)  $(LDFLAGS) -L$(LIBFT_DIR)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

r:
	make re && make clean && clear && ./minishell

.PHONY: all clean fclean re
