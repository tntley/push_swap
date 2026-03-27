/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanrandr <tanrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 22:29:15 by tanrandr          #+#    #+#             */
/*   Updated: 2026/03/26 16:24:14 by tanrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list_stack	*pop_node(t_list_stack **src)
{
	t_list_stack	*head;

	head = *src;
	if (head->next == head)
		*src = NULL;
	else
	{
		*src = head->next;
		(*src)->prev = head->prev;
		head->prev->next = *src;
	}
	return (head);
}

void	push(t_list_stack **src, t_list_stack **dest)
{
	t_list_stack	*head;

	if (!src || !*src)
		return ;
	head = pop_node(src);
	if (!*dest)
	{
		*dest = head;
		head->next = head;
		head->prev = head;
	}
	else
	{
		head->prev = (*dest)->prev;
		head->next = *dest;
		(*dest)->prev->next = head;
		(*dest)->prev = head;
		*dest = head;
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
