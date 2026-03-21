/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complexsort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanrandr <tanrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 23:05:15 by tanrandr          #+#    #+#             */
/*   Updated: 2026/03/21 23:13:59 by tanrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	complexsort(t_list_stack **a, t_list_stack **b)
{
	int size = sizeofstack(*a);
	int max_bits = 0;
	int i = 0;
	int j;


	while (((size - 1) >> max_bits) != 0)
		max_bits++;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if ((((*a)->index >> i) & 1) == 1)
				ra(a);
			else
				pb(a, b);
			j++;
		}
		while (*b)
			pa(b, a);
		i++;
	}
}
