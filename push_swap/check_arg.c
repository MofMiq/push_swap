/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marirodr <marirodr@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 12:35:42 by marirodr          #+#    #+#             */
/*   Updated: 2023/04/11 11:08:36 by marirodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Check is the arguments is a number.
cheackeamos caracter a caracter -> char *argv*/

int	is_number(char *argv)
{
	int	i;

	i = 0;
	if (is_sign(argv[i]) && argv[i + 1] != '\0')
		i++;
	while (argv[i] && is_digit(argv[i]))
		i++;
	if (argv[i] && !is_digit(argv[i]))
		return (0);
	return (1);
}

/* chaeks if there're duplicate numbers
cmp_number = 0 ->los argumentos son iguales
cmp_number = 1 ->los argumentos son distintos
return: 1 si existe duplica; 0 si no hay ninguno
int flag: boolean to know if the arguments had been parsed or not,
because where to begin to check the arguments depends on that
0 for when we use split; 1 for when not so we pass the program name
*/

int	ft_ndup(char **argv)
{
	int	i;
	int	j;
	int	z;

	i = 0;
	z = 0;
	while (argv[i])
	{
		j = i;
		if (ft_atol(argv[i]) == 0)
			z++;
		while (argv[j])
		{
			if ((j != i && cmp_number(argv[i], argv[j]) == 0) || (z > 1))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

/*check if the arguments are correctly "written"
int flag: boolean to know if the arguments had been parsed or not,
because where to begin to check the arguments depends on that
0 for when we use split; 1 for when not so we pass the program name*/

int	ft_arg_check(char **argv)
{
	int			i;
	long int	nb;

	i = 0;
	while (argv[i])
	{
		if (ft_strcmp("", argv[i]) == 0)
			return (0);
		if (!is_number(argv[i]))
			return (0);
		nb = ft_atol(argv[i]);
		if (nb < INT_MIN || nb > INT_MAX)
			return (0);
		i++;
	}
	if (ft_ndup(argv))
		return (0);
	return (1);
}
