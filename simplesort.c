/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simplesort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanrandr <tanrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 21:43:15 by tanrandr          #+#    #+#             */
/*   Updated: 2026/04/02 17:20:59 by tanrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	simplesort(t_list_stack **a, t_list_stack **b, t_list_bench *metric)
{
	int	min;

	if (sizeofstack(*a) == 1)
		return ;
	if (sizeofstack(*a) == 2)
	{
		if (compute_disorder(*a))
			do_sa(a, metric);
		return ;
	}
	while (sizeofstack(*a) > 3)
	{
		min = get_min_index(*a);
		move_to_top_a(a, min, metric);
		do_pb(a, b, metric);
	}
	sort_three(a, metric);
	while (*b)
		do_pa(b, a, metric);
}

int	get_min_index(t_list_stack *stack)
{
	int				min ;
	t_list_stack	*tmp;

	min = stack->index;
	tmp = stack->next;
	while (tmp != stack)
	{
		if (tmp->index < min)
			min = tmp->index;
		tmp = tmp->next;
	}
	return (min);
}

void	sort_three(t_list_stack **a, t_list_bench *metric)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->value;
	second = (*a)->next->value;
	third = (*a)->next->next->value;
	if (first > second && second < third && first < third)
	{
		do_sa(a, metric);
	}
	else if (first > second && second > third)
	{
		do_sa(a, metric);
		do_rra(a, metric);
	}
	else if (first > second && second < third && first > third)
		do_ra(a, metric);
	else if (first < second && second > third && first < third)
	{
		do_sa(a, metric);
		do_ra(a, metric);
	}
	else if (first < second && second > third && first > third)
		do_rra(a, metric);
}
