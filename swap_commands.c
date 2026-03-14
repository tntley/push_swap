/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanrandr <tanrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 05:22:15 by tanrandr          #+#    #+#             */
/*   Updated: 2026/03/14 22:18:51 by tanrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list_stack **stack)
{
	t_list_stack	*head;
	t_list_stack	*second;
	t_list_stack	*third;
	t_list_stack	*last;

	if (!(*stack) || (*stack)->next == (*stack))
		return;
	head = *stack;
	second = head->next;
	if (second->next == head)
	{
		(*stack) = second;
		return;
	}
	last = head->prev;
	third = second->next;
	last->next = second;
	second->prev = last;
	second->next = head;
	head->prev = second;
	head->next = third;
	third->prev = head;
	(*stack) = second;
}

void	sa(t_list_stack **a)
{
	swap(a);
	write(1, "sa\n", 3);
}

void	sb(t_list_stack **b)
{
	swap(b);
	write(1, "sb\n", 3);
}

void	ss(t_list_stack **a, t_list_stack **b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}
