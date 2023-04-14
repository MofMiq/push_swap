/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marirodr <marirodr@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 13:24:44 by marirodr          #+#    #+#             */
/*   Updated: 2023/04/14 12:57:46 by marirodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*check is the stack is already sorted when it's filled for the first time.
0 is false-> isn't sorted; 1 is true-> is already sorted so whe don't have to
make any operation.*/

int	ft_is_sorted(t_stack	*stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp->next != NULL)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

/*while (stack) //no puede ser stack->next porque tiene que entrar en el bucle 
cuando llega al ultimo nodo para comprobar si es el mayor*/

int	ft_highest_index(t_stack	*stack)
{
	int	highest;

	highest = stack->index;
	while (stack)
	{
		if (highest < stack->index)
			highest = stack->index;
		stack = stack->next;
	}
	return (highest);
}

/* tiene que ser **stack para que guardemos la direccion de memoria del
primer elemento de la lista y no perdamos la referencia.*/

void	ft_sort(t_stack	**stack_a, int stack_size)
{
	if (stack_size == 2)
		ft_sa(*stack_a);
	else if (stack_size == 3)
	{
		ft_sort_3(stack_a);
	}
	else
		return ;
}

	// else if (size > 3)
		//ft_printf("no esta hecho todavia xddd");

/* */

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
	else if ((*stack_a)->next->next->index == ft_highest_index(*stack_a))
		ft_sa(*stack_a);
}
