/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marirodr <marirodr@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 13:09:07 by marirodr          #+#    #+#             */
/*   Updated: 2023/04/24 16:02:09 by marirodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Assigns a position to each element of a stack from top to bottom in ascending
order. start at 0.*/

void	ft_position(t_stack **stack)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = *stack;
	while (tmp)
	{
		tmp->pos = i;
		tmp = tmp->next;
		i++;
	}
}

/*i_b: al indice del primer nodo de b (el actual), no cambia al lo largo de
la funcion.
i_a: se refiere al indice dentro del stack a ("en el array"), para ir
comparando con de a (un contador de toda la vida)
t_p: empieza en 0 y el entero que va guardar y actualizar la target position
en stack_b inicializamos tp en INT_MAX para ir colocando la target_position
en b pero en relaciona a los valores y posiciones en a. -> lo que haremos en
codigo es comparar el indice en a con el indice de b y comprobar si es 
mayor, ademas comprobamos que el indice de a sea menor que la target
position y vamos guardando las posiciones.
el segundo bucle es para: 
en el caso de que estemos ante el numero mayor de todas las pilas y por
tanto tenga que ir en la ultima posicion en a, le dejamos el valor max.
*/

int	ft_find_out_tp(t_stack **stack_a, int i_b, int i_a, int tp)
{
	t_stack	*tmp;

	tmp = *stack_a;
	while (tmp)
	{
		if (tmp->index > i_b && tmp->index < i_a)
		{
			i_a = tmp->index;
			tp = tmp->pos;
		}
		tmp = tmp->next;
	}
	if (i_a != INT_MAX)
	{
		//ft_printf("tp: %d", tp);
		return (tp);
	}
	tmp = *stack_a;
	while (tmp)
	{
		if (tmp->index < i_a)
		{
			i_a = tmp->index;
			tp = tmp->pos;
		}
		tmp = tmp->next;
	}
	return (tp);
}

/*this funcion fill pos (posiotion into the array) and target_pos from
the estrcuture's list. the imporant it's withing ft_find_out_tp and it's
to know where do we have to move the elemnets in stack_b to stack_a based
on the cost in order to be sorted correctly.*/

void	ft_write_target_position(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	int		tp;

	ft_position(stack_a);
	ft_position(stack_b);
	tmp = *stack_b;
	tp = 0;
	while (tmp)
	{
		tp = ft_find_out_tp(stack_a, tmp->index, INT_MAX, 0);
		tmp->target_pos = tp;
		tmp = tmp->next;
	}
}
