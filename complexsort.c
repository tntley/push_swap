/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complexsort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleandri <aleandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 23:05:15 by tanrandr          #+#    #+#             */
/*   Updated: 2026/03/25 10:11:50 by aleandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	complexsort(t_list_stack **a, t_list_stack **b, t_list_bench *metric)
{
	int	size;
	int	max_bits;
	int	i;
	int	j;

	i = 0;
	max_bits = 0;
	size = sizeofstack(*a);
	while (((size - 1) >> max_bits) != 0)
		max_bits++;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if ((((*a)->index >> i) & 1) == 1)
				do_ra(a, metric);
			else
				do_pb(a, b, metric);
			j++;
		}
		while (*b)
			do_pa(b, a, metric);
		i++;
	}
}
