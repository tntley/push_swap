/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanrandr <tanrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 19:23:06 by tanrandr          #+#    #+#             */
/*   Updated: 2026/03/25 04:56:42 by tanrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	char			**temp;
	int				i;
	char			*joint;
	t_list_stack	*a = NULL;
	t_list_stack	*b = NULL;
	int				sortmode;
	t_list_bench	*metric = NULL;
	//t_list_stack	*current;

	joint = "";
	i = 1;
	if (argc < 2)
		return (0);
	if(check_bench(&metric, argv[i]))
		i = 2;
	sortmode = define_sort_mode(argv[i]);
	if (sortmode != 0)
		i++;
	while (argv[i] && i < argc)
		joint = ft_strjoinspace(joint, argv[i++]);
	//printf("%s\n", joint);

	temp = ft_split(joint, ' ');
	manage_input(temp, &a);
	free_temp(temp);

	//FOLLOWING LINES ARE JUST TESTS
	/*current = a;
	while (current->next != a)
	{
		printf("%d, index : %d\n", current->value, current->index);
		current = current->next;
	}
	printf("%d, index : %d\n", current->value, current->index);
	printf("size of stack = %d\n", sizeofstack(a));
	printf("disorder : %f\n", compute_disorder(a));
	printf("sort mode number %d\n", sortmode);
	ra(&a);
	printf("new head value is : %d\n", a->value);
	printf("value of last node after rotation : %d\n", a->prev->value);
	rra(&a);
	printf("value of new first node : %d\n", a->value);
	printf("value of new second node : %d\n", a->next->value);
	pb(&a, &b);
	printf("value of new first node of stack a : %d\n", a->value);
	printf("value of new first node of stack b : %d\n", b->value);*/

	if (a)
		run_sort(&a, &b, sortmode, metric);
	/*current = a;
	while (current->next != a)
	{
		printf("%d\n", current->value);
		current = current->next;
	}
	printf("%d\n", current->value);*/
	/*if (!b)
		printf("stack B is empty");
	else
		printf("stack B is not empty");
	current = a;
	printf("\nTop of A is: %d\n", current->value);
	if (metric)
	{
		printf("Disorder : %f\n", metric->disorder);
		printf("ra : %d\n", metric->ra);
		printf("pb : %d\n", metric->pb);
		printf("rra : %d\n", metric->rra);
		printf("pa : %d\n", metric->pa);
		printf("sa : %d\n", metric->sa);
	}*/
	if (metric)
		print_metrics(metric, sortmode);
	return (0);
}

void	free_temp(char **temp)
{
	int	i;

	i = 0;
	while (temp[i])
	{
		free(temp[i]);
		i++;
	}
	free(temp);
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

void	define_bench(t_list_bench **metric)
{
	t_list_bench	*newnode;

	newnode = malloc(sizeof(t_list_bench));
	if (!newnode)
		return;
	ft_bzero(newnode, sizeof(t_list_bench));
	*metric = newnode;
}
