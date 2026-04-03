/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mediumsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanrandr <tanrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 21:44:16 by tanrandr          #+#    #+#             */
/*   Updated: 2026/04/03 14:05:59 by tanrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_back_to_a(t_list_stack **a, t_list_stack **b,
		t_list_bench *metric, int i)
{
	while (*b)
	{
		move_to_top_b(b, i - 1, metric);
		do_pa(b, a, metric);
		i--;
	}
}

void	mediumsort(t_list_stack **a, t_list_stack **b, t_list_bench *metric)
{
	int	size;
	int	chunk_size;
	int	i;

	size = sizeofstack(*a);
	chunk_size = ft_sqrt(size);
	i = 0;
	while (*a)
	{
		if ((*a)->index <= i)
		{
			do_pb(a, b, metric);
			do_rb(b, metric);
			i++;
		}
		else if ((*a)->index <= i + chunk_size)
		{
			do_pb(a, b, metric);
			i++;
		}
		else
			do_ra(a, metric);
	}
	push_back_to_a(a, b, metric, i);
}

int	ft_sqrt(int nb)
{
	int	sq;

	sq = 1;
	if (nb <= 0)
		return (0);
	else
	{
		while (sq * sq < nb)
			sq++;
		if (sq * sq == nb)
			return (sq);
		else
			return (sq - 1);
	}
}
