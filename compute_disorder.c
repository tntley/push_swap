/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanrandr <tanrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 03:54:42 by tanrandr          #+#    #+#             */
/*   Updated: 2026/03/14 04:02:39 by tanrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float	compute_disorder(t_list_stack *a)
{
	float			mistakes;
	float			pairs;
	t_list_stack	*node1;
	t_list_stack	*node2;

	pairs = 0.0;
	mistakes = 0.0;
	if (!a || a->next == a)
		return (mistakes);
	node1 = a;
	while (node1->next != a)
	{
		node2 = node1->next;
		while (node2 != a)
		{
			pairs += 1;
			if (node1->value > node2->value)
				mistakes += 1;
			node2 = node2->next;
		}
		node1 = node1->next;
	}
	return (mistakes / pairs);
}
