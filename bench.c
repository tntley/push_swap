/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanrandr <tanrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 02:39:49 by tanrandr          #+#    #+#             */
/*   Updated: 2026/03/26 17:06:09 by tanrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_metrics(t_list_bench *metric, int sortmode)
{
	print_disorder(metric->disorder);
	print_mode(sortmode, metric->disorder);
	print_total_ops(metric);
	print_ops(metric);
}

void	print_disorder(float disorder)
{
	int	result;
	int	front;
	int	back;

	result = (int)(disorder * 10000 + 0.5);
	front = result / 100;
	back = result % 100;
	ft_putstr_fd("[bench] disorder: ", 2);
	ft_putnbr_fd(front, 2);
	ft_putchar_fd('.', 2);
	ft_putnbr_fd(back, 2);
	if (back < 10)
		ft_putchar_fd('0', 2);
	ft_putstr_fd("%\n", 2);
}

void	print_mode(int sortmode, float disorder)
{
	ft_putstr_fd ("[bench] strategy: ", 2);
	if (sortmode == 1)
		ft_putendl_fd("Simple / O(n^2)", 2);
	else if (sortmode == 2)
		ft_putendl_fd("Medium / O(n * sqrt(n))", 2);
	else if (sortmode == 3)
		ft_putendl_fd("Complex / O(n*log(n))", 2);
	else if (sortmode == 0 || sortmode == -1)
	{
		if (disorder < 0.2)
			ft_putendl_fd("Adaptive / O(n^2)", 2);
		if (disorder >= 0.2 && disorder < 0.5)
			ft_putendl_fd("Adaptive / O(n * sqrt (n))", 2);
		if (disorder >= 0.5)
			ft_putendl_fd("Adaptive / O(n*log(n))", 2);
	}
}

void	print_total_ops(t_list_bench *metric)
{
	int	total;

	ft_putstr_fd("[bench] total_ops: ", 2);
	total = metric->sa + metric->sb
		+ metric->ss + metric->pa + metric->pb + metric->ra
		+ metric->rb + metric->rr + metric->rra + metric->rrb + metric->rrr;
	ft_putnbr_fd(total, 2);
	ft_putchar_fd('\n', 2);
}

void	print_ops(t_list_bench *metric)
{
	ft_putstr_fd("[bench] sa: ", 2);
	ft_putnbr_fd(metric->sa, 2);
	ft_putstr_fd("  sb: ", 2);
	ft_putnbr_fd(metric->sb, 2);
	ft_putstr_fd("  ss: ", 2);
	ft_putnbr_fd(metric->ss, 2);
	ft_putstr_fd("  pa: ", 2);
	ft_putnbr_fd(metric->pa, 2);
	ft_putstr_fd("  pb: ", 2);
	ft_putnbr_fd(metric->pb, 2);
	ft_putchar_fd('\n', 2);
	ft_putstr_fd("[bench] ra: ", 2);
	ft_putnbr_fd(metric->ra, 2);
	ft_putstr_fd("  rb: ", 2);
	ft_putnbr_fd(metric->rb, 2);
	ft_putstr_fd("  rr: ", 2);
	ft_putnbr_fd(metric->rr, 2);
	ft_putstr_fd("  rra: ", 2);
	ft_putnbr_fd(metric->rra, 2);
	ft_putstr_fd(" rrb: ", 2);
	ft_putnbr_fd(metric->rrb, 2);
	ft_putstr_fd("  rrr: ", 2);
	ft_putnbr_fd(metric->rrr, 2);
	ft_putchar_fd('\n', 2);
}
