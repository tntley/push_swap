/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mediumsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanrandr <tanrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 21:44:16 by tanrandr          #+#    #+#             */
/*   Updated: 2026/03/22 00:49:15 by tanrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	mediumsort(t_list_stack **a, t_list_stack **b)
{
	int	size = sizeofstack(*a);
	//int chunk_size = (size > 100) ? 35 : 15;
	int	chunk_size = sqrt(size); /*divide into sqrt n chunks, not default sized chunks*/
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
