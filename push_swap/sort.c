/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marirodr <marirodr@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 13:24:44 by marirodr          #+#    #+#             */
/*   Updated: 2023/04/24 18:59:29 by marirodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_3(t_stack	**stack_a)
{
	if ((*stack_a)->index == ft_highest_index(*stack_a))
	{
		ft_ra(stack_a);
		if (!ft_is_sorted(*stack_a))
		{
			ft_sa(*stack_a);
		}
	}
	else if ((*stack_a)->next->index == ft_highest_index(*stack_a))
	{
		ft_rra(stack_a);
		if (!ft_is_sorted(*stack_a))
			ft_sa(*stack_a);
	}
	else if ((*stack_a)->next->next->index == ft_highest_index(*stack_a) && !ft_is_sorted(*stack_a))
		ft_sa(*stack_a);
}

void	ft_sort_plus(t_stack **stack_a, t_stack **stack_b)
{
	ft_push_until_3(stack_a, stack_b);
	ft_sort_3(stack_a);
	while (*stack_b) //?? *
	{
		ft_write_target_position(stack_a, stack_b);
		
		ft_calculate_cost(stack_a, stack_b);
		//ft_print_list(*stack_a);
		//ft_print_list(*stack_b);
		ft_cheapest_cost(stack_a, stack_b);
	}
	if (!ft_is_sorted(*stack_a))
		ft_shift_stack(stack_a);
}

/*(stack_size / 2) > 3 : lo puedo hacer de otra menera???? probar
pushes all nodes of stack_a into stack_b, except the last three.
Also, make a previous ordenation pushing first the ones with
smaller indices.
p = it's a contador for the elements pushed into stack_b
i = it's a contador to control the "len" of stack_a*/

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

/*lowest is the position of the lowest index within the stack and we
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
