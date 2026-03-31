/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsinginput.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanrandr <tanrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 21:38:11 by tanrandr          #+#    #+#             */
/*   Updated: 2026/03/31 23:41:13 by tanrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	manage_input(char **temp, t_list_stack **a, t_list_flag *flag)
{
	int		i;

	i = 0;
	check_flags_split(temp, flag);
	while (temp[i])
	{
		if (!check_input(temp[i], a))
			return ;
		i++;
	}
}

int	check_input(char *temp, t_list_stack **a)
{
	long	prestack;

	if (!run_isdigit(temp))
	{
		error_and_free(a);
		return (0);
	}
	prestack = ft_atolong(temp);
	if (prestack > INT_MAX || prestack < INT_MIN)
	{
		error_and_free(a);
		return (0);
	}
	if (is_duplicate(*a, (int)prestack))
	{
		error_and_free(a);
		return (0);
	}
	build_stack(a, (int)prestack);
	return (1);
}

int	run_isdigit(char *temp)
{
	int		j;

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
