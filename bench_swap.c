/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanrandr <tanrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 03:45:24 by tanrandr          #+#    #+#             */
/*   Updated: 2026/03/25 03:46:10 by tanrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_sa(t_list_stack **a, t_list_bench *metric)
{
	sa(a);
	if (metric)
		metric->sa++;
}

void	do_sb(t_list_stack **b, t_list_bench *metric)
{
	sb(b);
	if (metric)
		metric->sb++;
}

void	do_ss(t_list_stack **a, t_list_stack **b, t_list_bench *metric)
{
	sa(a);
	sb(b);
	if (metric)
		metric->ss++;
}
