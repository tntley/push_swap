/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanrandr <tanrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 11:11:08 by tanrandr          #+#    #+#             */
/*   Updated: 2026/03/11 11:35:18 by tanrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list_stack	make_stack(char **temp, t_list_stack **a)
{
	if (!run_isdigit(temp))
		return (NULL);

}

int	run_isdigit(char **temp)
{
	int	i;
	int	j;

	i = 0;
	while (temp[i])
	{
		j = 0;
		while (temp[i][j])
		{
			if (!ft_isdigit(temp[i][j]))
			{
				write(2, "Error, non digit\n", 17);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
