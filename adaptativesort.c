/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptativesort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanrandr <tanrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 12:58:10 by tanrandr          #+#    #+#             */
/*   Updated: 2026/03/22 09:41:51 by tanrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	adaptativesort(t_list_stack **a, t_list_stack **b)
{
	float	disorder;

	disorder = compute_disorder(*a);
	if (disorder < 0.2)
		simplesort(a, b);
	else if (disorder >= 0.2 && disorder < 0.5)
		mediumsort(a, b);
	else if (disorder >= 0.5)
		complexsort(a, b);
}
