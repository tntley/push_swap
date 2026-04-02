# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tanrandr <tanrandr@student.42antananari    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/11 09:52:37 by tanrandr          #+#    #+#              #
#    Updated: 2026/04/02 16:46:06 by tanrandr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
CC = cc
CFLAGS = -Werror -Wextra -Wall
SRC = new.c rotate_commands.c parsinginput.c compute_disorder.c adaptivesort.c joinargs.c mediumsort.c push_commands.c reverserotate_commands.c simplesort.c sorting.c stackbuilding.c swap_commands.c complexsort.c utilsforsort.c bench.c bench_push.c bench_reverse_rotate.c bench_rotate.c bench_swap.c flags_from_argv.c flags_in_split.c
OBJ := $(SRC:.c=.o)

all: $(NAME)

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
