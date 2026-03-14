/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanrandr <tanrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 18:23:36 by tanrandr          #+#    #+#             */
/*   Updated: 2026/03/14 02:34:31 by tanrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <stdio.h>
# include <limits.h>

typedef struct	s_list_stack
{
	int					value;
	int					index;
	struct s_list_stack	*next;
	struct s_list_stack	*prev;
}				t_list_stack;

int		run_isdigit(char *temp);
long	ft_atolong(const char *temp);
int		is_duplicate(t_list_stack *a, int nb);
void	build_stack(t_list_stack **a, int nb);
void	define_indexes(t_list_stack *a);
int		sizeofstack(t_list_stack *a);




# endif
