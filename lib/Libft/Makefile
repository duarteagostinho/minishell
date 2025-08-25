# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/28 16:27:18 by mrapp-he          #+#    #+#              #
#    Updated: 2024/11/22 17:20:13 by mrapp-he         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC = ft_atoi.c ft_memcpy.c ft_strlcpy.c ft_bzero.c ft_memmove.c ft_strlen.c ft_calloc.c ft_memset.c ft_strmapi.c ft_isalnum.c ft_putchar_fd.c ft_strncmp.c ft_isalpha.c ft_putendl_fd.c ft_strnstr.c ft_isascii.c ft_putnbr_fd.c ft_strrchr.c ft_isdigit.c ft_putstr_fd.c ft_strtrim.c ft_isprint.c ft_strchr.c ft_substr.c ft_itoa.c ft_strdup.c ft_tolower.c ft_striteri.c ft_toupper.c ft_memchr.c ft_strjoin.c ft_memcmp.c ft_strlcat.c ft_split.c
SRC_BONUS = ft_lstadd_back.c ft_lstdelone.c ft_lstadd_front.c ft_lstiter.c ft_lstnew.c ft_lstclear.c ft_lstlast.c ft_lstsize.c ft_lstmap.c
OBJ := $(SRC:%.c=%.o)
OBJ_BONUS := $(SRC_BONUS:%.c=%.o)
CC = cc
CCFLGS = -Wall -Wextra -Werror
CPPFLGS = -I .

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)

%.o: %.c
	@$(CC) $(CPPFLGS) $(CCFLGS) -c $< -o $@

bonus: $(NAME) .bonus

.bonus: $(OBJ_BONUS)
	@ar rcs $(NAME) $(OBJ_BONUS)
	@touch .bonus
	
clean:
	@rm -f $(OBJ) $(OBJ_BONUS) .bonus

fclean: clean
	@rm -f $(NAME)
	
re: fclean all
