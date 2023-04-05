/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marirodr <marirodr@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 16:33:31 by marirodr          #+#    #+#             */
/*   Updated: 2023/04/05 17:34:03 by marirodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**ft_parse(char **argv)
{
	char	**str;

	str = ft_split(argv[1], ' ');
	if (!*str)
		exit(0);
	return (str);
}
