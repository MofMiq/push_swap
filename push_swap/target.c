/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marirodr <marirodr@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 13:09:07 by marirodr          #+#    #+#             */
/*   Updated: 2023/05/04 11:05:39 by marirodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Assigns a position to each element of a stack from top to bottom in ascending
order. Start at 0.*/

void	ft_position(t_stack **stack)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = *stack;
	while (tmp)
	{
		tmp->pos = i;
		tmp = tmp->next;
		i++;
	}
}

/*Picks the best target position in stack A for the given index of an element
in stack B.
i_b: refers to the index of the first node in b (the current one), which does not
change throughout the function.
i_a: is used to store and update the previous index of an element in a with a
higher value, in order to determine it's target position.
tp: starts at 0 and is the integer that will store and update the target position
in stack_b.
In the code, we compare the index_a with the index_b and check if it's greater.

The second loop is for the case where we are dealing with the largest number in
all the stacks and, therefore, it needs to go in the last position in a. In this
case, we set the value to the maximum.*/

int	ft_find_out_tp(t_stack **stack_a, int i_b, int i_a, int tp)
{
	t_stack	*tmp;

	tmp = *stack_a;
	while (tmp)
	{
		if (tmp->index > i_b && tmp->index < i_a)
		{
			i_a = tmp->index;
			tp = tmp->pos;
		}
		tmp = tmp->next;
	}
	if (i_a != INT_MAX)
		return (tp);
	tmp = *stack_a;
	while (tmp)
	{
		if (tmp->index < i_a)
		{
			i_a = tmp->index;
			tp = tmp->pos;
		}
		tmp = tmp->next;
	}
	return (tp);
}

/*This funcion fill pos and target_pos from the estrcuture's list. The imporant
thing it's withing ft_find_out_tp and it's to know where do we have to move the
elemnets in stack_b to stack_a based on the cost in order to be sorted correctly.
So, this function is basically to make a loop for the ft_find_out_tp function*/

void	ft_write_target_position(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	int		tp;

	ft_position(stack_a);
	ft_position(stack_b);
	tmp = *stack_b;
	tp = 0;
	while (tmp)
	{
		tp = ft_find_out_tp(stack_a, tmp->index, INT_MAX, 0);
		tmp->target_pos = tp;
		tmp = tmp->next;
	}
}
