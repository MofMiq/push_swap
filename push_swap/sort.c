/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marirodr <marirodr@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 13:24:44 by marirodr          #+#    #+#             */
/*   Updated: 2023/04/12 17:41:57 by marirodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*check is the stack is already sorted when it's filled for the first time.
0 is false-> isn't sorted; 1 is true-> is already sorted so whe don't have to
make any operation.*/

int	ft_is_sorted(t_stack	*stack)
{
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}
