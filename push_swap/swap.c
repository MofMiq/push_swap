/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marirodr <marirodr@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 13:58:53 by marirodr          #+#    #+#             */
/*   Updated: 2023/04/14 12:57:45 by marirodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//ft_swap(stack->index);
//ft_swap(stack->value);

void	ft_swap_ps(t_stack *stack)
{
	int	tmp;

	if (!stack || !stack->next)
		return ;
	tmp = stack->index;
	stack->index = stack->next->index;
	stack->next->index = tmp;
	tmp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = tmp;
}

void	ft_sa(t_stack *stack_a)
{
	ft_swap_ps(stack_a);
	ft_printf("sa\n");
}

void	ft_sb(t_stack *stack_b)
{
	ft_swap_ps(stack_b);
	ft_printf("sb\n");
}

void	ft_ss(t_stack *stack_a, t_stack *stack_b)
{
	ft_sa(stack_a);
	ft_sb(stack_b);
	ft_printf("ss\n");
}
