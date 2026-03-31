/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanrandr <tanrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 11:14:13 by tanrandr          #+#    #+#             */
/*   Updated: 2026/03/31 18:31:08 by tanrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	define_sort_mode(char *flag)
{
	int	mode;

	mode = 0;
	if (ft_strcmp(flag, "--simple") == 0)
		mode = 1;
	else if (ft_strcmp(flag, "--medium") == 0)
		mode = 2;
	else if (ft_strcmp(flag, "--complex") == 0)
		mode = 3;
	else if (ft_strcmp(flag, "--adaptive") == 0)
		mode = -1;
	return (mode);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return ((unsigned char) s1[i] - (unsigned char) s2[i]);
}

void	actual_sort(t_list_stack **a, t_list_flag *flag)
{
	t_list_stack	*b;
	t_list_bench	*metric;

	b = NULL;
	define_bench(&metric);
	if (a)
		run_sort(a, &b, flag->mode, metric);
	if (metric && a)
		print_metrics(metric, flag->mode);
	free(metric);
	metric = NULL;
}

void	run_sort(t_list_stack **a, t_list_stack **b, int sortmode,
			t_list_bench *metric)
{
	if (metric)
		metric->disorder = compute_disorder(*a);
	if (sortmode == 1)
		simplesort(a, b, metric);
	else if (sortmode == 2)
		mediumsort(a, b, metric);
	else if (sortmode == 3)
		complexsort(a, b, metric);
	else
		adaptivesort(a, b, metric);
}

void	free_everything(t_list_stack **a, char *joint,
			char **temp, t_list_flag **flag)
{
	int	i;

	i = 0;
	if (*a)
		freestack(a);
	while (temp[i])
	{
		free(temp[i]);
		i++;
	}
	free(temp);
	free(joint);
	free(*flag);
	*flag = NULL;
}
