/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_commands.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanrandr <tanrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 05:02:36 by tanrandr          #+#    #+#             */
/*   Updated: 2026/03/14 05:20:28 by tanrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_list_stack **stack)
{
	t_list_stack	*head;
	if (!(*stack) || (*stack)->next == (*stack))
		return;
	head = *stack;
	*stack = head->next;
}

void	ra(t_list_stack **a)
{
	rotate(&a);
	write(1, "ra\n", 3);
}

void	rb(t_list_stack **b)
{
	rotate(&b);
	write(1, "ra\n", 3);
}

void	rr(t_list_stack **a, t_list_stack **b)
{
	rotate(&a);
	rotate(&b);
	write(1, "rr\n", 3);
}
