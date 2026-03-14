/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanrandr <tanrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 18:23:36 by tanrandr          #+#    #+#             */
/*   Updated: 2026/03/14 05:46:45 by tanrandr         ###   ########.fr       */
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
float	compute_disorder(t_list_stack *a);

void	rotate(t_list_stack **stack);
void	ra(t_list_stack **a);
void	rb(t_list_stack **b);
void	rr(t_list_stack **a, t_list_stack **b);

void	swap(t_list_stack **stack);
void	sa(t_list_stack **a);
void	sb(t_list_stack **b);
void	ss(t_list_stack **a, t_list_stack **b);


# endif
