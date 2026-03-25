/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanrandr <tanrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 03:42:00 by tanrandr          #+#    #+#             */
/*   Updated: 2026/03/25 04:17:49 by tanrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_ra(t_list_stack **a, t_list_bench *metric)
{
	ra(a);
	if (metric)
		metric->ra++;
}

void	do_rb(t_list_stack **b, t_list_bench *metric)
{
	rb(b);
	if (metric)
		metric->rb++;
}

void	do_rr(t_list_stack **a, t_list_stack **b, t_list_bench *metric)
{
	ra(a);
	rb(b);
	if (metric)
		metric->rr++;
}
