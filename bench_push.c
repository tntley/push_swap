/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanrandr <tanrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 03:46:36 by tanrandr          #+#    #+#             */
/*   Updated: 2026/03/27 00:52:26 by tanrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_pa(t_list_stack **b, t_list_stack **a, t_list_bench *metric)
{
	pa(b, a);
	if (metric)
		metric->pa++;
}

void	do_pb(t_list_stack **a, t_list_stack **b, t_list_bench *metric)
{
	pb(a, b);
	if (metric)
		metric->pb++;
}
