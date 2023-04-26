/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marirodr <marirodr@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 12:55:24 by marirodr          #+#    #+#             */
/*   Updated: 2023/04/26 15:48:49 by marirodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Check that the character is a number.*/

int	ft_is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

/*Check that the character is a sign.*/

int	ft_is_sign(char c)
{
	if (c == '+' || c == '-')
		return (1);
	return (0);
}

/*This function compares the numbers passed by parameter to see if there are
non-literal duplicates such as +0 and -0 or 0001 and 1. The ft_strcmp function
compares two strings and returns 0 if they are equal, 1 if they are different.
Therefore, to follow that logic, this function returns 0 if it is true that the
numbers are equal and 1 when they are different, inverting the usual
true/false logic.*/

int	ft_cmp_number(char *s1, char *s2)
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

/*Check if the stack is already sorted. Returns 0 if is false, isn't sorted;
1 if is true; is already sorted so we don't have to make any operation.*/

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

/*Return the highest index within a stack.*/

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
