/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanrandr <tanrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 19:23:06 by tanrandr          #+#    #+#             */
/*   Updated: 2026/03/14 06:12:39 by tanrandr         ###   ########.fr       */
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
	long			prestack;
	t_list_stack	*current;

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
	i = 0;
	while (temp[i])
	{
		if (!run_isdigit(temp[i]))
		{
			write(2, "Error\n", 6);
			return (0);
		}
		prestack = ft_atolong(temp[i]);
		if (prestack > INT_MAX || prestack < INT_MIN)
		{
			write(2, "Error\n", 6);
			return (0);
		}
		if (is_duplicate(a, (int)prestack))
		{
			write(2, "Error\n", 6);
			return (0);
		}
		build_stack(&a, (int)prestack);
		i++;
	}
	define_indexes(a);


	current = a;
	while (current->next != a)
	{
		printf("%d, index : %d\n", current->value, current->index);
		current = current->next;
	}
	printf("%d, index : %d\n", current->value, current->index);
	printf("size of stack = %d\n", sizeofstack(a));
	printf("disorder : %f\n", compute_disorder(a));
	/*rotate(&a);
	printf("new head value is : %d\n", a->value);
	printf("value of last node after rotation : %d\n", a->prev->value);*/
	sa(&a);
	printf("value of new first node : %d\n", a->value);
	printf("value of new second node : %d\n", a->next->value);
	return (0);
}

int	run_isdigit(char *temp)
{
	int		j;
	long	nb;

	j = 0;
	while (temp[j])
	{
		j = 0;
		if(temp[j] == '-' || temp[j] == '+')
		{
			j++;
			if (!temp[j])
				return (0);
		}
		while (temp[j])
		{
			if (!ft_isdigit(temp[j]))
				return (0);
			j++;
		}
	}
	return (1);
}

long	ft_atolong(const char *temp)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (temp[i] == 32 || (temp[i] >= 9 && temp[i] <= 13))
		i++;
	if (temp[i] == '-')
	{
		sign = sign * -1;
		i++;
	}
	else if (temp[i] == '+')
		i++;
	while (temp[i] >= '0' && temp[i] <= '9' && temp[i] != '\0')
		result = (result * 10) + (temp[i++] - '0');
	result = result * sign;
	return (result);
}

int	is_duplicate(t_list_stack *a, int nb)
{
	t_list_stack	*temp;

	if (a == NULL)
		return (0);
	if (a->value == nb)
		return (1);
	temp = a->next;
	while (temp != a)
	{
		if (temp->value == nb)
			return (1);
		temp = temp->next;
	}
	return (0);
}

void	build_stack(t_list_stack **a, int nb)
{
	t_list_stack	*newnode;
	t_list_stack	*last;

	newnode = malloc (sizeof(t_list_stack));
	if (!newnode)
		return ;
	newnode->value = nb;
	newnode->index = -1;
	if (*a == NULL)
	{
		newnode->prev = newnode;
		newnode->next = newnode;
		*a = newnode;
	}
	else
	{
		last = (*a)->prev;
		newnode->next = (*a);
		newnode->prev = last;
		(*a)->prev = newnode;
		last->next = newnode;
	}
}

void	define_indexes(t_list_stack *a)
{
	int				i;
	int				j;
	t_list_stack	*fix;
	t_list_stack	*compareto;
	int				inferior;
	int				stacksize;

	stacksize = sizeofstack(a);
	fix = a;
	i = 0;
	while (i < stacksize)
	{
		j = 0;
		inferior = 0;
		compareto = a;
		while (j < stacksize)
		{
			if (compareto->value < fix->value)
				inferior++;
			compareto = compareto->next;
			j++;
		}
		fix->index = inferior;
		fix = fix->next;
		i++;
	}
}

int	sizeofstack(t_list_stack *a)
{
	t_list_stack	*temp;
	int				count;

	if (!a)
		return (0);
	temp = a;
	count = 0;
	while (temp->next != a)
	{
		count++;
		temp = temp->next;
	}
	count++;
	return (count);
}

float	compute_disorder(t_list_stack *a)
{
	float			mistakes;
	float			pairs;
	t_list_stack	*node1;
	t_list_stack	*node2;

	pairs = 0.0;
	mistakes = 0.0;
	if (!a || a->next == a)
		return (mistakes);
	node1 = a;
	while (node1->next != a)
	{
		node2 = node1->next;
		while (node2 != a)
		{
			pairs += 1;
			if (node1->value > node2->value)
				mistakes += 1;
			node2 = node2->next;
		}
		node1 = node1->next;
	}
	return (mistakes / pairs);
}

void	rotate(t_list_stack **stack)
{
	t_list_stack	*head;
	if (!(*stack) || (*stack)->next == (*stack))
		return;
	head = *stack;
	*stack = head->next;
}
