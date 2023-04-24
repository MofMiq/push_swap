/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marirodr <marirodr@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 10:04:51 by marirodr          #+#    #+#             */
/*   Updated: 2023/04/24 18:18:07 by marirodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Do rotate in both stacks simultaneously. This is because both costs are
positive numbers, which means that both are at the first half of their
respective stacks.*/

void	ft_rotate_both(t_stack **a, t_stack **b, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		ft_rr(a, b);
		(*cost_a)--;
		(*cost_b)--;
	}
}

/*Do reverse_rotate in both stacks simultaneously. This is because both 
costs are positive numbers, which means that both are at the first half of
their respective stacks.*/

void	ft_reverse_both(t_stack **a, t_stack **b, int *cost_a, int *cost_b)
{
	while (*cost_a < 0 && *cost_b < 0)
	{
		ft_rrr(a, b);
		(*cost_a)++;
		(*cost_b)++;
	}
}

/*With this function we choose what move are we doing in stack_a: if it's a
positve number, we do rotate; otherwise, if it's a negative number, we do
reverse_rotate; until cost reach 0 because that means that stack_a is in the 
correct position.*/

void	ft_do_rotate_a(t_stack **stack_a, int *cost_a)
{
	while (*cost_a)
	{
		if (*cost_a > 0)
		{
			ft_ra(stack_a);
			(*cost_a)--;
		}
		else if (*cost_a < 0)
		{
			ft_rra(stack_a);
			(*cost_a)++;
		}
	}
}

/*With this function we choose what move are we doing in stack_b: if it's a
positve number, we do rotate; otherwise, if it's a negative number, we do 
reverse_rotate; until cost reach 0 because that means that the element is at
the top of stack_b */

void	ft_do_rotate_b(t_stack **stack_b, int *cost_b)
{
	while (*cost_b)
	{
		if (*cost_b > 0)
		{
			ft_rb(stack_b);
			(*cost_b)--;
		}
		else if (*cost_b < 0)
		{
			ft_rrb(stack_b);
			(*cost_b)++;
		}
	}
}

/*Chooses which move we have to do to get both stacks in the correct position.
If both costs are positive, we do rotate in both stacks to save moves until one 
of them reach 0. Otherwise, if both cost are negative we instead must do
reverse_rotate in both stack as we have done previuously. When one of the cost 
become 0 means that in one stack we don't have to make more moves so we exit the
loop and make the aproppiate moves (rotate or reverse) in the other stack.
As a remainder, we must change the postion of both stack to put the desired
element at top of stack b and stack_a in the correct postion having as reference
the target postion.*/

void	ft_choose_move(t_stack **a, t_stack **b, int cost_a, int cost_b)
{
	if (cost_a > 0 && cost_b > 0)
		ft_rotate_both(a, b, &cost_a, &cost_b);
	else if (cost_a < 0 && cost_b < 0)
		ft_reverse_both(a, b, &cost_a, &cost_b);
	ft_do_rotate_a(a, &cost_a);
	ft_do_rotate_b(b, &cost_b);
	ft_pa(a, b);
}
