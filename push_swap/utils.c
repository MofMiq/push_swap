/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marirodr <marirodr@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 12:55:24 by marirodr          #+#    #+#             */
/*   Updated: 2023/04/14 12:57:41 by marirodr         ###   ########.fr       */
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
