/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_sort_mode.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanrandr <tanrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 11:14:13 by tanrandr          #+#    #+#             */
/*   Updated: 2026/03/17 12:21:16 by tanrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	define_sort_mode(char *flag)
{
	int	mode;

	mode = 0;
	if (ft_strcmp(flag, "--simple") == 0)
		mode = 1;
	if (ft_strcmp(flag, "--medium") == 0)
		mode = 2;
	if (ft_strcmp(flag, "--complex") == 0)
		mode = 3;
	if (ft_strcmp(flag, "--adaptative") == 0)
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
