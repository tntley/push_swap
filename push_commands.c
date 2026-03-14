/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanrandr <tanrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 22:29:15 by tanrandr          #+#    #+#             */
/*   Updated: 2026/03/14 23:02:58 by tanrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_list_stack **src, t_list_stack **dest)
{
	t_list_stack	*head;
	t_list_stack	*second;
	t_list_stack	*lastsrc;
	t_list_stack	*lastdest;

	if (!(*src))
		return;
	head = *src;
	second = head->next;
	lastsrc = head->prev;
	*src = second;
	second->prev = lastsrc;
	lastsrc->next = second;
	if (!(*dest))
	{
		(*dest) = head;
		head->next = head;
		head->prev = head;
	}
	else
	{
		lastdest = (*dest)->prev;
		lastdest->next = head;
		(*dest) = head;
	}
}

void	pa(t_list_stack **b, t_list_stack **a)
{
	push(b, a);
	write(1, "pa\n", 3);
}

void	pb(t_list_stack **a, t_list_stack **b)
{
	push(a, b);
	write(1, "pb\n", 3);
}
