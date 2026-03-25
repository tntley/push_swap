/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mediumsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanrandr <tanrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 21:44:16 by tanrandr          #+#    #+#             */
/*   Updated: 2026/03/25 03:54:40 by tanrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	mediumsort(t_list_stack **a, t_list_stack **b, t_list_bench *metric)
{
	int	size = sizeofstack(*a);
	int	chunk_size = ft_sqrt(size);
	int	i = 0;

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
	while (*b)
	{
		move_to_top(b, i - 1, metric);
		do_pa(b, a, metric);
		i--;
	}
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
