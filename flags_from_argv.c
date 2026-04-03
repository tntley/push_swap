/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_from_argv.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanrandr <tanrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 22:37:03 by tanrandr          #+#    #+#             */
/*   Updated: 2026/04/03 16:54:54 by tanrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_flags(char **argv, int *argc, t_list_flag *flag)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if ((!ft_strcmp(argv[i], "--bench") || !ft_strcmp(argv[i],
					"\"--bench\"")) && !(flag->bench))
		{
			remove_flag(argc, argv[i]);
			flag->bench = 1;
		}
		else if ((!ft_strcmp(argv[i], "--simple") || !ft_strcmp(argv[i],
					"\"--simple\"")) && !(flag->mode))
		{
			remove_flag(argc, argv[i]);
			flag->mode = 1;
		}
		check_flags_b(argv, argc, flag, i);
		i++;
	}
}

void	check_flags_b(char **argv, int *argc, t_list_flag *flag, int i)
{
	if ((!ft_strcmp(argv[i], "--medium") || !ft_strcmp(argv[i],
				"\"--medium\"")) && !(flag->mode))
	{
		remove_flag(argc, argv[i]);
		flag->mode = 2;
	}
	else if ((!ft_strcmp(argv[i], "--complex") || !ft_strcmp(argv[i],
				"\"--complex\"")) && !(flag->mode))
	{
		remove_flag(argc, argv[i]);
		flag->mode = 3;
	}
	else if ((!ft_strcmp(argv[i], "--adaptive") || !ft_strcmp(argv[i],
				"\"--adaptive\"")) && !(flag->mode))
	{
		remove_flag(argc, argv[i]);
		flag->mode = -1;
	}
}

void	remove_flag(int *argc, char *argv)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(argv))
	{
		ft_memset(argv, ' ', ft_strlen(argv));
		i++;
	}
	(*argc)--;
}
