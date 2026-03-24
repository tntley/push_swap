# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tanrandr <tanrandr@student.42antananari    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/11 09:52:37 by tanrandr          #+#    #+#              #
#    Updated: 2026/03/24 18:05:53 by tanrandr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
CC = gcc
CFLAGS = -Werror -Wextra -Wall
SRC = push_swap.c rotate_commands.c parsinginput.c compute_disorder.c adaptivesort.c ft_strjoinspace.c mediumsort.c push_commands.c reverserotate_commands.c simplesort.c sorting.c stackbuilding.c swap_commands.c complexsort.c utilsforsort.c
OBJ := $(SRC:.c=.o)

all: $(NAME) $(LIBFT)

$(LIBFT) :
	make -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -L$(LIBFT_DIR) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make clean -C ./libft
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	make fclean -C ./libft

re: fclean all
