/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marirodr <marirodr@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 10:12:59 by marirodr          #+#    #+#             */
/*   Updated: 2023/04/26 13:04:40 by marirodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*The last node of the list becomes the first one, because shifts all elements
of it down by 1. Code alternative:
	tmp = *stack;
	*stack = last;
	(*stack)->next = tmp;
*/

void	ft_reverse_rotate(t_stack **stack)
{
	t_stack	*penultimate;
	t_stack	*last;

	penultimate = ft_get_penultimate_node(*stack);
	last = ft_get_last_node(*stack);
	penultimate->next = NULL;
	last->next = *stack;
	stack[0] = last;
}

/*Does reverse rotate in stack_a*/

void	ft_rra(t_stack **stack_a)
{
	ft_reverse_rotate(stack_a);
	ft_printf("rra\n");
}

/*Does reverse rotate in stack_b*/

void	ft_rrb(t_stack **stack_b)
{
	ft_reverse_rotate(stack_b);
	ft_printf("rrb\n");
}

/*Does reverse rotate in both stacks*/

void	ft_rrr(t_stack **stack_a, t_stack **stack_b)
{
	ft_reverse_rotate(stack_a);
	ft_reverse_rotate(stack_b);
	ft_printf("rrr\n");
}
