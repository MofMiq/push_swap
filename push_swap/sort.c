/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marirodr <marirodr@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 13:24:44 by marirodr          #+#    #+#             */
/*   Updated: 2023/04/20 12:35:26 by marirodr         ###   ########.fr       */
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

void	ft_decide(t_stack	**stack_a, t_stack **stack_b, int stack_size)
{
	if (stack_size == 2)
		ft_sa(*stack_a);
	else if (stack_size == 3)
		ft_sort_3(stack_a);
	else if (stack_size > 3)
		ft_sort_plus(stack_a, stack_b);
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

void	ft_sort_plus(t_stack **stack_a, t_stack **stack_b)
{
	ft_push_until_3(stack_a, stack_b);
	ft_sort_3(stack_a);
	while (stack_b) //?? *
	{
		ft_write_target_position(stack_a, stack_b);
		ft_calculate_cost();
	}
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
	while (i < stack_size && p < (stack_size / 2) && (stack_size / 2) > 3)
	{
		if ((*stack_a)->index <= stack_size)
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
