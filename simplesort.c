/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simplesort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanrandr <tanrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 21:43:15 by tanrandr          #+#    #+#             */
/*   Updated: 2026/03/24 17:23:38 by tanrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void simplesort(t_list_stack **a, t_list_stack **b)
{
	int min;

	while (sizeofstack(*a) > 3)
	{
		min = get_min_index(*a);
		move_to_top(a, min);
		pb(a, b);
	}
	sort_three(a);
	while (*b)
		pa(b, a);
}

int	get_min_index(t_list_stack *stack)
{
	int	min ;
	t_list_stack	*tmp;

	min = stack->index;
	tmp = stack->next;
	while (tmp != stack)
	{
		if (tmp->index < min)
			min = tmp->index;
		tmp = tmp->next;
	}
	return min;
}

void	sort_three(t_list_stack **a)
{
	int first = (*a)->value;
	int second = (*a)->next->value;
	int third = (*a)->next->next->value;


	if (first > second && second < third && first < third)
		sa(a);
	else if (first > second && second > third)
	{
		sa(a);
		rra(a);
	}
	else if (first > second && second < third && first > third)
		ra(a);
	else if (first < second && second > third && first < third)
	{
		sa(a);
		ra(a);
	}
	else if (first < second && second > third && first > third)
		rra(a);
}
