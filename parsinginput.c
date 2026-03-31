/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsinginput.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanrandr <tanrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 21:38:11 by tanrandr          #+#    #+#             */
/*   Updated: 2026/03/31 18:34:25 by tanrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	manage_input(char **temp, t_list_stack **a, t_list_flag *flag, char *joint)
{
	long	prestack;
	int		i;

	i = 0;
	check_flags_split(temp, flag);
	while (temp[i])
	{
		if (!run_isdigit(temp[i]))
		{
			error_and_free(a, joint, temp, &flag);
			return ;
		}
		prestack = ft_atolong(temp[i]);
		if (prestack > INT_MAX || prestack < INT_MIN)
		{
			error_and_free(a, joint, temp, &flag);
			return ;
		}
		if (is_duplicate(*a, (int)prestack))
		{
			error_and_free(a, joint, temp, &flag);
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

void	error_and_free(t_list_stack **a, char *joint, char **temp, t_list_flag **flag)
{
	ft_putendl_fd("Error", 2);
	free_everything(a, joint, temp, flag);
}

void	check_flags_split(char **temp, t_list_flag *flag)
{
	int	i;
	int	removed;

	i = 0;
	while (temp[i])
	{
		removed = 0;
		if ((!ft_strcmp(temp[i], "--bench") || !ft_strcmp(temp[i], "\"--bench\"")) && !(flag->bench))
		{
			remove_flag_split(temp, i);
			flag->bench = 1;
			removed = 1;
		}
		else if ((!ft_strcmp(temp[i], "--simple") || !ft_strcmp(temp[i], "\"--simple\"")) && !(flag->mode))
		{
			remove_flag_split(temp, i);
			flag->mode = 1;
			removed = 1;
		}
		else if ((!ft_strcmp(temp[i], "--medium") || !ft_strcmp(temp[i], "\"--medium\"")) && !(flag->mode))
		{
			remove_flag_split(temp, i);
			flag->mode = 2;
			removed = 1;
		}
		else if ((!ft_strcmp(temp[i], "--complex") || !ft_strcmp(temp[i], "\"--complex\"")) && !(flag->mode))
		{
			remove_flag_split(temp, i);
			flag->mode = 3;
			removed = 1;
		}
		else if ((!ft_strcmp(temp[i], "--adaptive") || !ft_strcmp(temp[i], "\"--adaptive\"")) && !(flag->mode))
		{
			remove_flag_split(temp, i);
			flag->mode = -1;
			removed = 1;
		}
		if (!removed)
			i++;
	}
}

void	remove_flag_split(char **temp, int i)
{
	char	*current;

	current = temp[i];
	while (temp[i])
	{
		temp[i] = temp[i + 1];
		i++;
	}
	free(current);
}

void	define_bench(t_list_bench **metric)
{
	t_list_bench	*newnode;

	newnode = malloc(sizeof(t_list_bench));
	if (!newnode)
		return ;
	ft_bzero(newnode, sizeof(t_list_bench));
	*metric = newnode;
}
