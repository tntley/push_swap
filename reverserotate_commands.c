/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverserotate_commands.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleandri <aleandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 22:19:29 by tanrandr          #+#    #+#             */
/*   Updated: 2026/03/25 10:53:19 by aleandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverserotate(t_list_stack **stack)
{
	if (!(*stack) || (*stack)->next == (*stack))
		return ;
	(*stack) = (*stack)->prev;
}

void	rra(t_list_stack **a)
{
	reverserotate(a);
	write(1, "rra\n", 4);
}

void	rrb(t_list_stack **b)
{
	reverserotate(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_list_stack **a, t_list_stack **b)
{
	reverserotate(a);
	reverserotate(b);
	write(1, "rrr\n", 4);
}
