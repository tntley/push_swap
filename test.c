/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanrandr <tanrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 00:27:18 by tanrandr          #+#    #+#             */
/*   Updated: 2026/03/25 00:58:19 by tanrandr         ###   ########.fr       */
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
