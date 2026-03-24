/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mediumsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanrandr <tanrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 21:44:16 by tanrandr          #+#    #+#             */
/*   Updated: 2026/03/24 17:39:30 by tanrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	mediumsort(t_list_stack **a, t_list_stack **b)
{
	int	size = sizeofstack(*a);
	int	chunk_size = ft_sqrt(size);
	int	i = 0;

	while (*a)
	{
		if ((*a)->index <= i)
		{
			pb(a, b);
			rb(b);
			i++;
		}
		else if ((*a)->index <= i + chunk_size)
		{
			pb(a, b);
			i++;
		}
		else
			ra(a);
	}
	while (*b)
	{
		//int max_idx = sizeofstack(*b) - 1;
		move_to_top(b, i - 1);
		pa(b, a);
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
