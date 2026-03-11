# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tanrandr <tanrandr@student.42antananari    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/11 09:52:37 by tanrandr          #+#    #+#              #
#    Updated: 2026/03/11 11:35:54 by tanrandr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pushswap.a
LIBFT = ./libft/libft.a
CC = gcc
CFLAGS = -Werror -Wextra -Wall -c
SRC = make_stack.c
OBJ := $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	make -C ./libft
	cp $(LIBFT) $@
	ar rcs $@

clean:
	make clean -C ./libft

fclean: clean
	rm -f $(NAME)
	make fclean -C ./libft

re: fclean all
