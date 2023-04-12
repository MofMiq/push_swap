/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marirodr <marirodr@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 13:39:17 by marirodr          #+#    #+#             */
/*   Updated: 2023/04/11 11:01:43 by marirodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*function based on ft_list_new from libft, but changed to fit our structure
in push_swap and where we inizialitate it. -1 is for structure's variables that
we are not using for the moment and to clearly see it*/

t_stack	*ft_new_stack(int value)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->value = value;
	stack->index = 0;
	stack->pos = -1;
	stack->target_pos = -1;
	stack->cost_a = -1;
	stack->cost_b = -1;
	stack->next = NULL;
	return (stack);
}

/*return the last element of the stack*/

t_stack	*ft_get_last_node(t_stack *stack)
{
	while (stack->next != NULL)
		stack = stack->next;
	return (stack);
}

int	ft_stack_size(t_stack *stack)
{
	int	size;

	size = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		stack = stack->next;
		size++;
	}
	return (size);
}

/*function based on ft_lstadd_back from libft, but changed to fit our structure
in push_swap and add a 'new' node at the end of the stack.
	last = ft_get_last_node(*stack);
	last->next = new;
	[new]->[new2]->NULL =>[new]->[last]->[new3]->NULL
	*/

t_stack	*ft_stack_add_last(t_stack **stack, t_stack *new)
{
	if (!new)
		return (NULL);
	if (*stack == NULL)
		*stack = new;
	else
		ft_get_last_node(*stack)->next = new;
	return (*stack);
}

void	ft_print_list(t_stack *stack_a)
{
	while (stack_a)
	{
		ft_printf("v:%d i:%d\n", stack_a->value, stack_a->index);
		stack_a = stack_a->next;
	}
}
