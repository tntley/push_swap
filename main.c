/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanrandr <tanrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 19:23:06 by tanrandr          #+#    #+#             */
/*   Updated: 2026/03/11 12:46:18 by tanrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	char			**temp;
	int				i;
	char			*joint;
	/*t_list_stack	*a;
	t_list_stack	*b;*/

	i = 1;
	joint = "";
	if (argc == 2)
		temp = ft_split(argv[1], ' ');
	else
	{
		while (argv[i] && i < argc)
			joint = ft_strjoin(joint, argv[i++]);
		temp = ft_split(joint, ' ');
	}
	printf("%d", run_isdigit(temp));
	/*a = NULL;
	b = NULL;
	make_stack(temp, &a)*/
	/*i = 0;
	while (temp[i])
		printf("%s\n", temp[i++]);
	return (0);*/
}

int	run_isdigit(char **temp)
{
	int	i;
	int	j;

	i = 0;
	while (temp[i])
	{
		j = 0;
		if(temp[i][j] == '-' || temp[i][j] == '+')
		{
			j++;
			if (!temp[i][j])
			{
				write(2, "Error\n", 6);
				return (0);
			}
		}
		while (temp[i][j])
		{
			if (!ft_isdigit(temp[i][j]))
			{
				write(2, "Error\n", 7);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
