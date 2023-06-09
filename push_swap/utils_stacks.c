/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marirodr <marirodr@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 13:39:17 by marirodr          #+#    #+#             */
/*   Updated: 2023/05/04 11:05:43 by marirodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Function based on ft_list_new from libft, but has been modified to fit the
structure of push_swap and where we inizialitate it. The "-1" is used for 
structure variables that we aren't currently using, to make it clearer.*/

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

/*Return the last element of the stack.*/

t_stack	*ft_get_last_node(t_stack *stack)
{
	while (stack && stack->next != NULL)
		stack = stack->next;
	return (stack);
}

/*Return the penultimate of the stack.*/

t_stack	*ft_get_penultimate_node(t_stack *stack)
{
	while (stack->next->next != NULL)
		stack = stack->next;
	return (stack);
}

/*Returns the size of the list, (without the NULL, because isn't a node)*/

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

/*Function based on ft_list_new from libft, but has been modified to fit the
structure of push_swap and add a 'new' node at the end of the stack.
	last = ft_get_last_node(*stack);
	last->next = new;
	[new]->[new2]->NULL =>[new]->[new2]->[last]->NULL
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
