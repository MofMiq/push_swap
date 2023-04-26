/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marirodr <marirodr@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 12:35:42 by marirodr          #+#    #+#             */
/*   Updated: 2023/04/26 15:49:13 by marirodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Check if character by character if the arguments are numbers.*/

int	ft_is_number(char *argv)
{
	int	i;

	i = 0;
	if (ft_is_sign(argv[i]) && argv[i + 1] != '\0')
		i++;
	while (argv[i] && ft_is_digit(argv[i]))
		i++;
	if (argv[i] && !ft_is_digit(argv[i]))
		return (0);
	return (1);
}

/*Check if there're duplicate numbers.
return values: 1 if there's a duplicate; 0 if there's none.*/

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
			if ((j != i && ft_cmp_number(argv[i], argv[j]) == 0) || (z > 1))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

/*Check that the arguments are correctly have been passed correctly acording
to the scpecified format.*/

int	ft_arg_check(char **argv)
{
	int			i;
	long int	nb;

	i = 0;
	while (argv[i])
	{
		if (ft_strcmp("", argv[i]) == 0)
			return (0);
		if (!ft_is_number(argv[i]))
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
