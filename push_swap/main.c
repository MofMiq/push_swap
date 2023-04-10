/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marirodr <marirodr@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 11:26:03 by marirodr          #+#    #+#             */
/*   Updated: 2023/04/10 17:33:22 by marirodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*in this function, if everything is correct we only call other functions in
order.*/
void	ft_push_swap(char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		stack_size;

	stack_a = ft_fill_stack(argv);
	stack_b = NULL;
	//can i free with ft_free_pointerx2 argv yet?
	stack_size = ft_stack_size(stack_a + 1); //+1 para empezar a indezar el 0?
}

/*we check if there're enough arguments. if that's the case, we check if it's
onlt one argument "" or not. int any case, we use ft_split to generate substrings
in where are gonna be allocated the numbers we later are going to sort*/

int	main(int argc, char **argv)
{
	char	**splited;
	int		flag;

	splited = NULL;
	flag = 1;
	if (argc < 2)
		return (0);
	if (argc == 2) //(&& argv[1] != "")
	{
		splited = ft_parse(argv);
		flag = 0;
	}
	else
		splited = argv;
	if (!ft_arg_check(splited, flag))
	{
		if (flag == 0)
			ft_free_pointer_x2(splited);
		ft_printf("%s¡¡¡¡error!!!!%s\n", RED, END);
		return (0);
	}
	ft_print_pointer_x2(splited);
	ft_printf("%sok%s\n", GREEN, END);
}
