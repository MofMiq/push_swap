/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_n_indexing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marirodr <marirodr@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 12:19:01 by marirodr          #+#    #+#             */
/*   Updated: 2023/04/12 10:26:14 by marirodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*fill stacks a with the arguments changed previously to numbers.*/

t_stack	*ft_fill_stack(char **argv)
{
	t_stack	*stack_a;
	int		nb;
	int		i;

	stack_a = NULL;
	nb = 0;
	i = 0;
	while (argv[i])
	{
		nb = ft_atoi(argv[i]);
		ft_stack_add_last(&stack_a, ft_new_stack(nb));
		i++;
	}
	return (stack_a);
}

/*asignamos de mayor a menor porque tenemos el indice mayor al tener el tamaño
de laa lista. puntero auxiliar con el que recorrer el stack; puntero largest
para ir guardando la valor mayor con cada vuelta; int v: para ir guardando el
valor mas alto de cada vuelta.*/

void	ft_index_stack(t_stack *stack_a, int stack_size)
{
	t_stack	*aux;
	t_stack	*largest;
	int		v;

	while (stack_size > 0)
	{
		aux = stack_a;
		largest = NULL;
		v = INT_MIN;
		while (aux)
		{
			if (aux->value > v && aux->index == 0)
			{
				v = aux->value;
				largest = aux;
				aux = stack_a;
			}
			aux = aux->next;
		}
		if (largest != NULL)
			largest->index = stack_size;
		stack_size--;
	}
}
