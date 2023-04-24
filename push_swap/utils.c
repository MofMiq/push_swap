/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marirodr <marirodr@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 12:55:24 by marirodr          #+#    #+#             */
/*   Updated: 2023/04/24 10:44:47 by marirodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	is_sign(char c)
{
	if (c == '+' || c == '-')
		return (1);
	return (0);
}

/*como en strcmp si los strings son iguales devuelve 0 y si son distintos, 1;
en cmp_number por seguir esa logica, invierto el true/false de toda la vida:
si 0 es que sí son inguales los string; si devuelve 1, en algun punto son
diferentes*/

int	cmp_number(char *s1, char *s2)
{
	if (*s1 == '+' && *s2 != '+')
			s1++;
	else if (*s2 == '+' && *s1 != '+')
			s2++;
	while (*s1 == '0' && *(s1 + 1) != '\0')
		s1++;
	while (*s2 == '0' && *(s2 + 1) != '\0')
		s2++;
	if (ft_strcmp(s1, s2) == 0)
		return (0);
	return (1);
}

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
