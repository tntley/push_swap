/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   joinargs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanrandr <tanrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 10:27:23 by tanrandr          #+#    #+#             */
/*   Updated: 2026/03/27 00:35:36 by tanrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strjoinspace(const char *s1, const char *s2)
{
	char	*result;
	int		i;
	int		j;
	int		len;

	len = ft_strlen(s1) + ft_strlen(s2);
	result = malloc (sizeof(char) * (len + 2));
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
		result[j++] = s1[i++];
	result[j++] = ' ';
	i = 0;
	while (s2[i] != '\0')
		result[j++] = s2[i++];
	result[j] = '\0';
	return (result);
}
