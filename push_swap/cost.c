/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marirodr <marirodr@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 12:21:02 by marirodr          #+#    #+#             */
/*   Updated: 2023/04/20 14:43:55 by marirodr         ###   ########.fr       */
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
		if (tmp_b->target_pos > (size_b / 2))
			tmp_b->cost_a = (size_a - tmp_b->target_pos) * -1;
		tmp_b = tmp_b->next;
	}
}
