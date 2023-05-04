/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marirodr <marirodr@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 13:24:44 by marirodr          #+#    #+#             */
/*   Updated: 2023/05/04 11:05:36 by marirodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*We sort three elements separately because there are only five possible cases,
excluding the one case where the numbers are already sorted, and this way, we
ensure that it's sorted in two moves or fewer.*/

void	ft_sort_3(t_stack	**stack_a)
{
	if ((*stack_a)->index == ft_highest_index(*stack_a))
	{
		ft_ra(stack_a);
		if (!ft_is_sorted(*stack_a))
			ft_sa(*stack_a);
	}
	else if ((*stack_a)->next->index == ft_highest_index(*stack_a))
	{
		ft_rra(stack_a);
		if (!ft_is_sorted(*stack_a))
			ft_sa(*stack_a);
	}
	else if ((*stack_a)->next->next->index == ft_highest_index(*stack_a)
		&& !ft_is_sorted(*stack_a))
		ft_sa(*stack_a);
}

/*This function handles stacks with more than three elements. First, we
push elements onto stack_b until there are only three elements left in stack_a.
Then, we sort those remaining three numbers in stack_a so that when we push 
elements onto stack_a, they are introduced in an ordered and sensible way. On
the other hand, while there are elements in stack_b, we will be calculating the
destination position, calculating the costs of moving an element from one stack
to another, choosing the one that costs less to move to save actions, and making
those movements. Once we have done this with all the elements in stack_b until
it's empty, we check that the element with the smallest index is on top of
stack_a.*/

void	ft_sort_plus(t_stack **stack_a, t_stack **stack_b)
{
	ft_push_until_3(stack_a, stack_b);
	ft_sort_3(stack_a);
	while (*stack_b)
	{
		ft_write_target_position(stack_a, stack_b);
		ft_calculate_cost(stack_a, stack_b);
		ft_cheapest_cost(stack_a, stack_b);
	}
	if (!ft_is_sorted(*stack_a))
		ft_shift_stack(stack_a);
}

/*Push elements onto stack_b until there are only three elements left in
stack_a. Also, make a previous ordenation pushing first the ones with
smaller indices.
p = it's a contador for the elements pushed into stack_b.
i = it's a contador to control the "len" of stack_a.*/

void	ft_push_until_3(t_stack **stack_a, t_stack **stack_b)
{
	int	stack_size;
	int	i;
	int	p;

	stack_size = ft_stack_size(*stack_a);
	i = 0;
	p = 0;
	while (i < stack_size && p < (stack_size / 2) && stack_size > 6)
	{
		if ((*stack_a)->index <= stack_size / 2)
		{
			ft_pb(stack_a, stack_b);
			p++;
		}
		else
			ft_ra(stack_a);
		i++;
	}
	while ((stack_size - p) > 3)
	{
		ft_pb(stack_a, stack_b);
		p++;
	}
}

/*Lowest is the position of the lowest index within the stack and we
get it to shift the already sorted stack_a but getting it in the rigth
position.*/

void	ft_shift_stack(t_stack **stack_a)
{
	int	stack_size;
	int	lowest;

	stack_size = ft_stack_size(*stack_a);
	lowest = ft_lowest(stack_a);
	if (lowest < (stack_size / 2))
	{
		while (lowest > 0)
		{
			ft_ra(stack_a);
			lowest--;
		}
	}
	else
	{
		while (lowest < stack_size)
		{
			ft_rra(stack_a);
			lowest++;
		}
	}
}

/*Return the current position of the element with the lowest index
within the stack_a -in case stack_a is not sorted already*/

int	ft_lowest(t_stack **stack_a)
{
	t_stack	*tmp;
	int		pos;
	int		index;

	ft_position(stack_a);
	tmp = *stack_a;
	pos = tmp->pos;
	index = INT_MAX;
	while (tmp)
	{
		if (tmp->index < index)
		{
			index = tmp->index;
			pos = tmp->pos;
		}
		tmp = tmp->next;
	}
	return (pos);
}
