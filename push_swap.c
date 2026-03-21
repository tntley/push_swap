/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanrandr <tanrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 19:23:06 by tanrandr          #+#    #+#             */
/*   Updated: 2026/03/22 00:35:13 by tanrandr         ###   ########.fr       */
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
	t_list_stack	*current;

	joint = "";
	if (argc < 2)
		return (0);
	sortmode = define_sort_mode(argv[1]);
	if (sortmode == 0)
		i = 1;
	else
		i = 2;
	while (argv[i] && i < argc)
		joint = ft_strjoinspace(joint, argv[i++]);
	temp = ft_split(joint, ' ');
	manage_input(temp, &a);

	//FOLLOWING LINES ARE JUST TESTS
	current = a;
	while (current->next != a)
	{
		printf("%d, index : %d\n", current->value, current->index);
		current = current->next;
	}
	printf("%d, index : %d\n", current->value, current->index);
	printf("size of stack = %d\n", sizeofstack(a));
	printf("disorder : %f\n", compute_disorder(a));
	/*printf("sort mode number %d\n", sortmode);
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
		run_sort(&a, &b, sortmode);
	current = a;
	while (current->next != a)
	{
		printf("%d\n", current->value);
		current = current->next;
	}
	printf("%d\n", current->value);
	freestack(&a);
	return (0);
}
