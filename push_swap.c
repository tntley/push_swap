/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanrandr <tanrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 19:23:06 by tanrandr          #+#    #+#             */
/*   Updated: 2026/03/31 17:41:28 by tanrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list_bench	*metric;
	int				i;

	i = 1;
	metric = NULL;
	if (argc < 2)
		return (0);
	if (check_bench(&metric, argv[i]))
		i = 2;
	parsing(argv, argc, i, metric);
	return (0);
}

void	parsing(char **argv, int argc, int i, t_list_bench *metric)
{
	char			**temp;
	char			*joint;
	t_list_stack	*a;
	int				sortmode;
	char			*hold;

	a = NULL;
	joint = ft_strdup("");
	sortmode = define_sort_mode(argv[i]);
	if (sortmode != 0)
		i++;
	if (!argv[i])
		error_and_free(&a);
	while (argv[i] && i < argc)
	{
		hold = joint;
		joint = ft_strjoinspace(joint, argv[i++]);
		free(hold);
	}
	temp = ft_split(joint, ' ');
	manage_input(temp, &a);
	if (a)
	{
		define_indexes(a);
		actual_sort(&a, metric, sortmode);
		free_everything(&a, &metric, joint, temp);
	}
}

int	check_bench(t_list_bench **metric, char *argv)
{
	if (!ft_strcmp(argv, "--bench"))
	{
		define_bench(metric);
		return (1);
	}
	else
		return (0);
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

void	free_everything(t_list_stack **a, char *joint,
			char **temp)
{
	int	i;

	i = 0;
	freestack(a);
	while (temp[i])
	{
		free(temp[i]);
		i++;
	}
	free(temp);
	free(joint);
	/*free(*metric);
	*metric = NULL;*/
}
