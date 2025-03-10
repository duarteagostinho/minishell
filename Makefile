# Variables
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = $(wildcard *.c src/*.c)
OBJS = $(SRCS:.c=.o)
NAME = minishell

# ft_printf variables
FT_PRINTF_DIR = ft_printf
FT_PRINTF_SRCS = $(wildcard $(FT_PRINTF_DIR)/*.c)
FT_PRINTF_OBJS = $(FT_PRINTF_SRCS:.c=.o)
FT_PRINTF_LIB = $(FT_PRINTF_DIR)/libftprintf.a

# libft variables
LIBFT_DIR = libft
LIBFT_SRCS = $(wildcard $(LIBFT_DIR)/*.c)
LIBFT_OBJS = $(LIBFT_SRCS:.c=.o)
LIBFT_LIB = $(LIBFT_DIR)/libft.a

# get_next_line variables
GNL_DIR = get_next_line
GNL_SRCS = $(wildcard $(GNL_DIR)/*.c)
GNL_OBJS = $(GNL_SRCS:.c=.o)

# Rules
all: $(NAME)

$(LIBFT_LIB): $(LIBFT_OBJS)
	ar rcs $(LIBFT_LIB) $(LIBFT_OBJS)

$(FT_PRINTF_LIB): $(FT_PRINTF_OBJS)
	ar rcs $(FT_PRINTF_LIB) $(FT_PRINTF_OBJS)

$(FT_PRINTF_LIB):
	$(MAKE) -C $(FT_PRINTF_DIR)

$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(FT_PRINTF_LIB) $(LIBFT_LIB)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L$(FT_PRINTF_DIR) -lftprintf -L$(LIBFT_DIR) -lft

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(FT_PRINTF_DIR) clean
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(FT_PRINTF_DIR) fclean
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
