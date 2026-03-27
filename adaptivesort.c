/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptivesort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanrandr <tanrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 12:58:10 by tanrandr          #+#    #+#             */
/*   Updated: 2026/03/27 02:48:24 by tanrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	adaptivesort(t_list_stack **a, t_list_stack **b, t_list_bench *metric)
{
	float	disorder;
	int		size;

	size = sizeofstack(*a);
	disorder = compute_disorder(*a);
	if (disorder < 0.2 || size <= 10)
		simplesort(a, b, metric);
	else if ((disorder >= 0.2 && disorder < 0.5) || (size > 10 && size <= 100))
		mediumsort(a, b, metric);
	else if (disorder >= 0.5)
		complexsort(a, b, metric);
}
