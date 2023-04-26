/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marirodr <marirodr@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 12:25:39 by marirodr          #+#    #+#             */
/*   Updated: 2023/04/26 13:02:51 by marirodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Take the top element from the src stack and moves it to the top of the dst
stack. If the source stack is empty, it does nothing.
(*src)->next = *dst // we make the nect pointer of the first node in *src to
*dst, which the first time points to NULL.
*dst = *src; // we copy only the one node because it's link with the src list
has been "broken". Without this line, the first node of *src points to NULL
because *dst initially points to NULL*/

void	ft_push(t_stack **src, t_stack **dst)
{
	t_stack	*tmp;

	if (!*src)
		return ;
	tmp = (*src)->next;
	(*src)->next = *dst;
	*dst = *src;
	*src = tmp;
}

/*Does push from stack_b to stack_a*/

void	ft_pa(t_stack	**stack_a, t_stack **stack_b)
{
	ft_push(stack_b, stack_a);
	ft_printf("pa\n");
}

/*Does push from stack_a to stack_b*/

void	ft_pb(t_stack	**stack_a, t_stack **stack_b)
{
	ft_push(stack_a, stack_b);
	ft_printf("pb\n");
}
