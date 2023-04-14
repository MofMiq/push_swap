/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marirodr <marirodr@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 11:26:03 by marirodr          #+#    #+#             */
/*   Updated: 2023/04/14 12:57:51 by marirodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*to search leaks in the program*/

void	ft_leaks(void)
{
	system("leaks -q push_swap");
}

/*only to check if the all elements of the list are correctly filled and
indexed. Also, to check if the operations are done correctly. */

void	ft_print_list(t_stack *stack_a)
{
	while (stack_a)
	{
		ft_printf("v:%d i:%d\n", stack_a->value, stack_a->index);
		stack_a = stack_a->next;
	}
	ft_printf("----\n");
}

/*in this function, if everything is correct we only call other functions in
order.*/

void	ft_push_swap(char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		stack_size;

	stack_a = ft_fill_stack(argv);
	stack_b = NULL;
	stack_size = ft_stack_size(stack_a);
	ft_index_stack(stack_a, stack_size);
	if (ft_is_sorted(stack_a))
		ft_free_stack(&stack_a);
	else
	{
		ft_sort(&stack_a, stack_size);
	}
	ft_free_stack(&stack_a);
}

/*we check if there're enough arguments. if that's the case, we check if it's
onlt one argument "" or not. int any case, we use ft_split to generate substrings
in where are gonna be allocated the numbers we later are going to sort. we use
to know what must be freed, only when we call ft_parse*/
//atexit(ft_leaks);
//	if (argc == 2) //(&& argv[1] != "")

int	main(int argc, char **argv)
{
	char	**splited;
	int		flag;

	flag = 0;
	splited = NULL;
	if (argc < 2)
		return (0);
	if (argc == 2)
	{
		splited = ft_parse(argv);
		flag = 1;
	}
	else
		splited = ++argv;
	if (!ft_arg_check(splited))
	{
		if (flag == 1)
			ft_free_pointer_x2(splited);
		ft_printf("%s¡¡¡¡error!!!!%s\n", RED, END);
		return (0);
	}
	ft_push_swap(splited);
	if (flag == 1)
		ft_free_pointer_x2(splited);
}
