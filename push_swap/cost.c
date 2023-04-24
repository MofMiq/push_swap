/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marirodr <marirodr@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 12:21:02 by marirodr          #+#    #+#             */
/*   Updated: 2023/04/24 18:53:17 by marirodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*size_b / 2 para dividir el stack en 2 mitades porque para la top vamos a hacer
rb y para la bottom vamos a hacer rrb. 
??? que pasa cuando el stack_b es impar ???
el coste de rr lo vamos a hacer negativo
para que cuando tengamos que hacer los movimientos solo con mirar el signo 
sepamos del tiron que rotate tenemos que hacer.
si tatno cost_a como cost_b tienen el mismo signo podemos ahorrar movs al mover
los dos stacks al mismo tiempo
como explicar operaciones ??*/

/*¡¡¡¡¡¡¡¡¡REPASO AL ESTAS OPERACIONES!!!!!*/

void	ft_calculate_cost(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;
	int		size_a;
	int		size_b;

	tmp_a = *stack_a;
	tmp_b = *stack_b;
	size_a = ft_stack_size(tmp_a);
	size_b = ft_stack_size(tmp_b);
	while (tmp_b)
	{
		tmp_b->cost_b = tmp_b->pos;
		if (tmp_b->pos > (size_b / 2))
			tmp_b->cost_b = (size_b - tmp_b->pos) * -1;
		tmp_b->cost_a = tmp_b->target_pos;
		if (tmp_b->target_pos > (size_a / 2))
			tmp_b->cost_a = (size_a - tmp_b->target_pos) * -1;
		tmp_b = tmp_b->next;
	}
//	ft_print_list(*stack_b);
//	pause();
}

/*find the element in stack_b with the cheapest cost to move to stack_a
and we call other function to make the correct moves in both stack to 
positionate both in the right postion. If there're various costs with
the same value, we take the firt one we find.*/

void	ft_cheapest_cost(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	int		cheapest;
	int		cost_a;
	int		cost_b;

	tmp = *stack_b;
	cheapest = INT_MAX;
	while (tmp)
	{
		if (ft_abs(tmp->cost_a) + ft_abs(tmp->cost_b) < ft_abs(cheapest))
		{
			cheapest = ft_abs(tmp->cost_a) + ft_abs(tmp->cost_b);
			cost_a = tmp->cost_a;
			cost_b = tmp->cost_b;
		}
		tmp = tmp->next;
	}
	//ft_printf("cheapest: %d\n", cheapest);
	ft_choose_move(stack_a, stack_b, cost_a, cost_b);
}
