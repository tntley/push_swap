/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanrandr <tanrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 00:27:18 by tanrandr          #+#    #+#             */
/*   Updated: 2026/03/31 18:07:42 by tanrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list_bench *metric;

	if(check_bench(&metric, argv[1]))
	{
		printf("%d\n", metric->disorder);
		printf("%d\n", metric->sa);
		printf("%d\n", argc);
	}
	else
		printf("%s", "Error");
	return (0);
}

int	check_bench(t_list_bench **metric,  char *argv)
{
	if (!ft_strcmp(argv, "--bench"))
	{
		define_bench(metric);
		return (1);
	}
	else
		return (0);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return ((unsigned char) s1[i] - (unsigned char) s2[i]);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*str;
	size_t			i;

	i = 0;
	str = (unsigned char *) s;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
}

void	define_bench(t_list_bench **metric)
{
	t_list_bench	*newnode;

	newnode = malloc(sizeof(t_list_bench));
	if (!newnode)
		return;
	ft_bzero(newnode, sizeof(t_list_bench));
	*metric = newnode;
}



int main(int argc, char **argv)
{
	t_list_flag		*flag;
	//t_list_bench	*metric;
	int				i;
	char			*joint;
	char			*hold;
	char			**temp;
	t_list_stack	*a;

	i = 1;
	//metric = NULL;
	flag = NULL;
	a = NULL;
	joint = ft_strdup("");
	if (argc < 2)
		return (0);
	define_flag_struct(&flag);
	check_flags(argv, &argc, flag);
	i = 1;
	while (argv[i])
	{
		hold = joint;
		joint = ft_strjoinspace(hold, argv[i++]);
		free(hold);
	}
	printf("numbers : %s\n", joint);
	printf("bench : %d, mode : %d\n", flag->bench, flag->mode);
	printf("final arg number : %d\n", argc);
	temp = ft_split(joint, ' ');
	i = 0;
	while (temp[i])
	{
		printf("%s\n", temp[i]);
		i++;
	}
	manage_input(temp, &a, flag);

	i = 0;
	while (temp[i])
	{
		printf("%s\n", temp[i]);
		i++;
	}

	if (a)
	{
		define_indexes(a);
		actual_sort(&a, flag);
		free_everything(&a, joint, temp);
	}

	printf("bench : %d, mode : %d\n", flag->bench, flag->mode);
	return (0);
}
