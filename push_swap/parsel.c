/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marirodr <marirodr@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 16:33:31 by marirodr          #+#    #+#             */
/*   Updated: 2023/04/26 12:50:06 by marirodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Function to print the numbers, only to check is they're correctly taken
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

/*Function to separate arguments in a string if the console passed a single
string with quotation marks (""), like "1 5 2".*/

char	**ft_parse(char **argv)
{
	char	**str;

	if (ft_strcmp("", argv[1]) == 0)
	{
		ft_printf("¡¡¡error!!!\n");
		exit(1);
	}
	str = ft_split(argv[1], ' ');
	if (!*str)
		exit(1);
	return (str);
}
