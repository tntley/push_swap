/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanrandr <tanrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 22:22:14 by tanrandr          #+#    #+#             */
/*   Updated: 2026/04/03 16:55:29 by tanrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list_flag		*flag;
	char			*joint;

	if (argc < 2)
		return (0);
	flag = NULL;
	joint = ft_strdup("");
	define_flag_struct(&flag);
	check_flags(argv, &argc, flag);
	parsing(argv, flag, joint);
	return (0);
}

void	define_flag_struct(t_list_flag **flag)
{
	t_list_flag	*newnode;

	newnode = malloc(sizeof(t_list_flag));
	if (!newnode)
		return ;
	ft_bzero(newnode, sizeof(t_list_flag));
	*flag = newnode;
}

void	parsing(char **argv, t_list_flag *flag, char *joint)
{
	int				i;
	char			*hold;
	char			**temp;
	t_list_stack	*a;

	i = 1;
	a = NULL;
	while (argv[i])
	{
		/*if (check_pre_split(argv[i]))
		{
			ft_putendl_fd("Error", 2);
			free(joint);
			free(flag);
			flag = NULL;
			return ;
		}*/
		hold = joint;
		joint = ft_strjoinspace(hold, argv[i++]);
		free(hold);
	}
	temp = ft_split(joint, ' ');
	manage_input(temp, &a, flag);
	if (a)
	{
		define_indexes(a);
		actual_sort(&a, flag);
	}
	free_everything(&a, joint, temp, &flag);
}

int	check_pre_split(char *arg)
{
	int	i;

	i = 0;
	if (arg[i] == '\0')
		return (1);
	while (arg[i])
	{
		if (arg[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}
