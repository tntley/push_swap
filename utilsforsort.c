/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilsforsort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanrandr <tanrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 23:19:17 by tanrandr          #+#    #+#             */
/*   Updated: 2026/03/26 16:37:27 by tanrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_to_top_a(t_list_stack **stack,
			int target_idx, t_list_bench *metric)
{
	int				pos;
	t_list_stack	*tmp;
	int				size;

	pos = 0;
	tmp = *stack;
	size = sizeofstack(*stack);
	while (tmp->index != target_idx && pos < size)
	{
		pos++;
		tmp = tmp->next;
	}
	if (pos == size)
		return ;
	if (pos <= size / 2)
		while ((*stack)->index != target_idx)
			do_ra(stack, metric);
	else
		while ((*stack)->index != target_idx)
			do_rra(stack, metric);
}

void	move_to_top_b(t_list_stack **stack, int target_idx,
			t_list_bench *metric)
{
	int				pos;
	t_list_stack	*tmp;
	int				size;

	pos = 0;
	tmp = *stack;
	size = sizeofstack(*stack);
	while (tmp->index != target_idx && pos < size)
	{
		pos++;
		tmp = tmp->next;
	}
	if (pos == size)
		return ;
	if (pos <= size / 2)
		while ((*stack)->index != target_idx)
			do_rb(stack, metric);
	else
		while ((*stack)->index != target_idx)
			do_rrb(stack, metric);
}
