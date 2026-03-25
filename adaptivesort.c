/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptivesort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanrandr <tanrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 12:58:10 by tanrandr          #+#    #+#             */
/*   Updated: 2026/03/25 03:56:57 by tanrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	adaptivesort(t_list_stack **a, t_list_stack **b, t_list_bench *metric)
{
	float	disorder;

	disorder = compute_disorder(*a);
	if (disorder < 0.2)
		simplesort(a, b, metric);
	else if (disorder >= 0.2 && disorder < 0.5)
		mediumsort(a, b, metric);
	else if (disorder >= 0.5)
		complexsort(a, b, metric);
}
