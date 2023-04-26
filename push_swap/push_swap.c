/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marirodr <marirodr@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 11:26:03 by marirodr          #+#    #+#             */
/*   Updated: 2023/04/26 15:40:26 by marirodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*To search leaks in the program, not valid to send*/

void	ft_leaks(void)
{
	system("leaks -q push_swap");
}

/*This funcion is used to veritfy if all elements of the list are correctly 
filled and indexed. Aditionally, it's used to check if the operations are done
correctly.*/

void	ft_print_list(t_stack *stack_a)
{
	while (stack_a)
	{
		ft_printf("v:%d\ti:%d\tpos:%d\ttp:%d\tcost_a:%d\tcost_b:%d\n", stack_a->value,
			stack_a->index, stack_a->pos, stack_a->target_pos, stack_a->cost_a,
			stack_a->cost_b);
		stack_a = stack_a->next;
	}
	ft_printf("----\n");
}

/*With this function, we simply route the program to one or another function
depending on the number of elements.*/

void	ft_decide(t_stack	**stack_a, t_stack **stack_b, int stack_size)
{
	if (stack_size == 2)
		ft_sa(*stack_a);
	else if (stack_size == 3)
		ft_sort_3(stack_a);
	else if (stack_size > 3)
		ft_sort_plus(stack_a, stack_b);
}

/*In this function, if everything is correct we only need call other functions
in order to sort the stack.*/

void	ft_push_swap(char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		stack_size;

	stack_a = ft_fill_stack(argv);
	stack_b = NULL;
	stack_size = ft_stack_size(stack_a);
	ft_index_stack(stack_a, stack_size);
	if (!ft_is_sorted(stack_a))
		ft_decide(&stack_a, &stack_b, stack_size);
	ft_free_stack(&stack_a);
	ft_free_stack(&stack_b);
}

/*We first check if there're enough arguments. If that's the case, we check if
it's only one argument between double quotation marks ("") or not. In any case,
we use ft_split to generate substrings where the numbers we later sort will be
allocated.*/
//atexit(ft_leaks);

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
			ft_free_double_pointer(splited);
		ft_printf("¡¡¡error!!!\n");
		return (0);
	}
	ft_push_swap(splited);
	if (flag == 1)
		ft_free_double_pointer(splited);
}
