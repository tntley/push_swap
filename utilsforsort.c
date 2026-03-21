/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilsforsort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanrandr <tanrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 23:19:17 by tanrandr          #+#    #+#             */
/*   Updated: 2026/03/21 23:19:56 by tanrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_to_top(t_list_stack **stack, int target_idx)
{
	int pos = 0;
	t_list_stack *tmp = *stack;
	int size = sizeofstack(*stack);


	while (tmp->index != target_idx)
	{
		pos++;
		tmp = tmp->next;
	}
	if (pos <= size / 2)
		while ((*stack)->index != target_idx) ra(stack);
	else
		while ((*stack)->index != target_idx) rra(stack);
}
