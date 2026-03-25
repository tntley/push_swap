/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_reverse_rotate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanrandr <tanrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 03:50:43 by tanrandr          #+#    #+#             */
/*   Updated: 2026/03/25 03:51:02 by tanrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_rra(t_list_stack **a, t_list_bench *metric)
{
	rra(a);
	if (metric)
		metric->rra++;
}

void	do_rrb(t_list_stack **b, t_list_bench *metric)
{
	rrb(b);
	if (metric)
		metric->rrb++;
}

void	do_rrr(t_list_stack **a, t_list_stack **b, t_list_bench *metric)
{
	rra(a);
	rrb(b);
	if (metric)
		metric->rrr++;
}
