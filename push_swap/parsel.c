/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marirodr <marirodr@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 16:33:31 by marirodr          #+#    #+#             */
/*   Updated: 2023/04/11 13:37:48 by marirodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*function to print the numbers, only to check is they're correctly taken
in the stack*/

void	ft_print_pointer_x2(char **argv)
{
	int	i;

	i = 0;
	while (argv[i] != NULL)
	{
		ft_printf("%s\n", argv[i]);
		i++;
	}
}

/*function to separate arguments in string if the consoled passed arguments it's
a single string with "", like "1 5 2"*/

char	**ft_parse(char **argv)
{
	char	**str;

	str = ft_split(argv[1], ' ');
	if (!*str)
		exit(0);
	return (str);
}
