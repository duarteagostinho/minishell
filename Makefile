CC = cc
CFLAGS = -Wall -Werror -Wextra -Ilib -g
SRCS = $(shell find src/ -type f -name '*.c')
OBJS = $(SRCS:.c=.o)
NAME = minishell
LIBFT_DIR = lib/Libft
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	LDFLAGS = -lft -lreadline
else ifeq ($(UNAME_S),Darwin)
	LDFLAGS = -lft -L$(shell brew --prefix readline)/lib -lreadline
	CFLAGS += -I$(shell brew --prefix readline)/include
else
	LDFLAGS = -lft -lreadline
endif
LIBFT_SRCS =$(shell find $(LIBFT_DIR) -type f -name '*.c')
LIBFT_OBJS = $(LIBFT_SRCS:.c=.o)
LIBFT_LIB = $(LIBFT_DIR)/libft.a

all: $(NAME)

install-deps:
	@echo "Installing dependencies (readline, build tools) for your OS..."
	@if command -v apt-get >/dev/null 2>&1; then \
		sudo apt-get update && sudo apt-get install -y build-essential libreadline-dev || true; \
	elif command -v dnf >/dev/null 2>&1; then \
		sudo dnf install -y make gcc readline-devel || true; \
	elif command -v yum >/dev/null 2>&1; then \
		sudo yum install -y make gcc readline-devel || true; \
	elif command -v pacman >/dev/null 2>&1; then \
		sudo pacman -Sy --noconfirm base-devel readline || true; \
	elif command -v brew >/dev/null 2>&1; then \
		brew install readline || true; \
	else \
		echo "No supported package manager found. Please install readline (and build tools) manually." >&2; exit 1; \
	fi


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
	rm -f $(NAME) $(DEPS_MARKER)
	make -C $(LIBFT_DIR) fclean

re: fclean all

val: re
	valgrind --show-leak-kinds=all --leak-check=full --track-origins=yes --track-fds=all --suppressions=readline.supp ./minishell

.PHONY: all clean fclean re
