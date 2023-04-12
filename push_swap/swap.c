/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marirodr <marirodr@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 13:58:53 by marirodr          #+#    #+#             */
/*   Updated: 2023/04/11 16:38:33 by marirodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_ps(t_stack *stack)
{
	int	tmp;

	if (!stack || !stack->next)
		return ;
	tmp = stack->index;
	stack->index = stack->next->index;
	stack->next->index = tmp;
	//ft_swap(stack->index);
	tmp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = tmp;
	//ft_swap(stack->value);
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
