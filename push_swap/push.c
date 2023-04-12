/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marirodr <marirodr@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 12:25:39 by marirodr          #+#    #+#             */
/*   Updated: 2023/04/12 13:15:46 by marirodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*take the first element at the top of the stack src and put it at the top of
stack dst. Does nothing if src is empty.*/

void	ft_push(t_stack **src, t_stack **dst)
{
	t_stack	*tmp;

	if (!*src)
		return ;
	tmp = (*src)->next;
	(*src)->next = *dst;// hacemos que el next del 1º nodo de *src apunte a *dst, que inicialmente apunta a NULL 
	*dst = *src; //copio solo el 1º nodo que apunta a *src y ya es solo uno porque en el paso anterior se ha "roto" su "enlaze" con la lista src. sin esta linea eñ 1º nodo de *src apunta a NULL porque *dst inicialmente apunta a NULL
	*src = tmp;
}

void	ft_pa(t_stack	**stack_a, t_stack **stack_b)
{
	ft_push(stack_b, stack_a);
	ft_printf("pa\n");
}

void	ft_pb(t_stack	**stack_a, t_stack **stack_b)
{
	ft_push(stack_a, stack_b);
	ft_printf("pb\n");
}
