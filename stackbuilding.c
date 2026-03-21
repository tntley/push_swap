/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackbuilding.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanrandr <tanrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 21:39:43 by tanrandr          #+#    #+#             */
/*   Updated: 2026/03/21 22:09:53 by tanrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	freestack(t_list_stack **stack)
{
	t_list_stack	*head;
	t_list_stack	*hold;
	t_list_stack	*following;

	if (!stack || !(*stack))
		return;
	head = *stack;
	hold = head->next;
	while (hold != head)
	{
		following = hold->next;
		free(hold);
		hold = following;
	}
	free(hold);
	*stack = NULL;
}
