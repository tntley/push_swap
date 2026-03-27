/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsinginput.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanrandr <tanrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 21:38:11 by tanrandr          #+#    #+#             */
/*   Updated: 2026/03/27 07:52:56 by tanrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	manage_input(char **temp, t_list_stack **a)
{
	long	prestack;
	int		i;

	i = 0;
	while (temp[i])
	{
		if (!run_isdigit(temp[i]))
		{
			error_and_free(a);
			return ;
		}
		prestack = ft_atolong(temp[i]);
		if (prestack > INT_MAX || prestack < INT_MIN)
		{
			error_and_free(a);
			return ;
		}
		if (is_duplicate(*a, (int)prestack))
		{
			error_and_free(a);
			return ;
		}
		build_stack(a, (int)prestack);
		i++;
	}
}

int	run_isdigit(char *temp)
{
	int		j;

	j = 0;
	while (temp[j])
	{
		j = 0;
		if (temp[j] == '-' || temp[j] == '+')
		{
			j++;
			if (!temp[j])
				return (0);
		}
		while (temp[j])
		{
			if (!ft_isdigit(temp[j]))
				return (0);
			j++;
		}
	}
	return (1);
}

long	ft_atolong(const char *temp)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (temp[i] == 32 || (temp[i] >= 9 && temp[i] <= 13))
		i++;
	if (temp[i] == '-')
	{
		sign = sign * -1;
		i++;
	}
	else if (temp[i] == '+')
		i++;
	while (temp[i] >= '0' && temp[i] <= '9' && temp[i] != '\0')
		result = (result * 10) + (temp[i++] - '0');
	result = result * sign;
	return (result);
}

int	is_duplicate(t_list_stack *a, int nb)
{
	t_list_stack	*temp;

	if (a == NULL)
		return (0);
	if (a->value == nb)
		return (1);
	temp = a->next;
	while (temp != a)
	{
		if (temp->value == nb)
			return (1);
		temp = temp->next;
	}
	return (0);
}

void	error_and_free(t_list_stack **a)
{
	ft_putendl_fd("Error", 2);
	if (*a)
		freestack(a);
}
