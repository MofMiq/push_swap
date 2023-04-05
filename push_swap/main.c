/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marirodr <marirodr@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 11:26:03 by marirodr          #+#    #+#             */
/*   Updated: 2023/04/05 18:13:59 by marirodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	//t_stack	*stack_a;
	t_stack	*stack_b;
	//int		size;
	char	**split;
	int		flag;

	split == NULL;
	flag = 0;
	if (argc < 2)
		return (0);
	if (argc == 2)
	{
		split = ft_parse(argv);
		flag = 1;
	}
	else
		split = argv;
	if (!ft_arg_check(split))
	{
		ft_printf("¡¡¡¡error!!!!\n");
		return (0);
	}
	ft_printf("ok\n");
	stack_b = NULL;
}
