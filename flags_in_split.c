/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_in_split.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanrandr <tanrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 22:40:36 by tanrandr          #+#    #+#             */
/*   Updated: 2026/03/31 22:54:10 by tanrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_flags_split(char **temp, t_list_flag *flag)
{
	int	i;
	int	removed;

	i = 0;
	while (temp[i])
	{
		removed = 0;
		if ((!ft_strcmp(temp[i], "--bench") || !ft_strcmp(temp[i],
					"\"--bench\"")) && !(flag->bench))
		{
			remove_flag_split(temp, i);
			flag->bench = 1;
			removed = 1;
		}
		else if ((!ft_strcmp(temp[i], "--simple") || !ft_strcmp(temp[i],
					"\"--simple\"")) && !(flag->mode))
		{
			remove_flag_split(temp, i);
			flag->mode = 1;
			removed = 1;
		}
		check_flags_split_b(temp, flag, i, &removed);
		if (!removed)
			i++;
	}
}

void	check_flags_split_b(char **temp, t_list_flag *flag, int i, int *removed)
{
	if ((!ft_strcmp(temp[i], "--medium") || !ft_strcmp(temp[i],
				"\"--medium\"")) && !(flag->mode))
	{
		remove_flag_split(temp, i);
		flag->mode = 2;
		*removed = 1;
	}
	else if ((!ft_strcmp(temp[i], "--complex") || !ft_strcmp(temp[i],
				"\"--complex\"")) && !(flag->mode))
	{
		remove_flag_split(temp, i);
		flag->mode = 3;
		*removed = 1;
	}
	else if ((!ft_strcmp(temp[i], "--adaptive") || !ft_strcmp(temp[i],
				"\"--adaptive\"")) && !(flag->mode))
	{
		remove_flag_split(temp, i);
		flag->mode = -1;
		*removed = 1;
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
