/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_n_indexing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marirodr <marirodr@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 12:19:01 by marirodr          #+#    #+#             */
/*   Updated: 2023/05/04 11:04:53 by marirodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Fill stack_a with the previosuly converted numeric values of the arguments.*/

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

/*This function adds an index to the strcuture which represents the positions
in the stack of an element if the stack was already sorted in ascending order.
We assign from highest to lowest because we have the highest index already
since we ha the stack_size.
We start indexing at 1.*/

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
