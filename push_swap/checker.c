/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marirodr <marirodr@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 16:38:03 by marirodr          #+#    #+#             */
/*   Updated: 2023/04/27 18:38:29 by marirodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*void	ft_leaks(void)
{
	system("leaks -q checker");
}*/

void	ft_check_op(t_stack **stack_a, t_stack **stack_b, char *str)
{
	if (ft_strcmp(str, "ra\n") == 0)
		ft_rotate(stack_a);
	else if (ft_strcmp(str, "rb\n") == 0)
		ft_rotate(stack_b);
	else if (ft_strcmp(str, "rr\n") == 0)
	{
		ft_rotate(stack_a);
		ft_rotate(stack_b);
	}
	else if (ft_strcmp(str, "rra\n") == 0)
		ft_reverse_rotate(stack_a);
	else if (ft_strcmp(str, "rrb\n") == 0)
		ft_reverse_rotate(stack_b);
	else if (ft_strcmp(str, "rrr\n") == 0)
	{
		ft_reverse_rotate(stack_a);
		ft_reverse_rotate(stack_b);
	}
	else if (ft_strcmp(str, "sa\n") == 0)
		ft_swap_ps(*stack_a);
	else
		ft_check_op_2(stack_a, stack_b, str);
}

void	ft_check_op_2(t_stack **stack_a, t_stack **stack_b, char *str)
{
	if (ft_strcmp(str, "pa\n") == 0)
		ft_push(stack_b, stack_a);
	else if (ft_strcmp(str, "pb\n") == 0)
		ft_push(stack_a, stack_b);
	else
		ft_error_checker(stack_a, stack_b);
}

void	ft_error_checker(t_stack **stack_a, t_stack **stack_b)
{
	ft_free_stack(stack_a);
	ft_free_stack(stack_b);
	write(2, "Error\n", 6);
	exit(1);
}

void	ft_checker(char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*str;

	stack_a = ft_fill_stack(argv);
	stack_b = NULL;
	str = get_next_line(0);
	while (str)
	{
		ft_check_op(&stack_a, &stack_b, str);
		free(str);
		str = get_next_line(0);
	}
	if (ft_is_sorted(stack_a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	ft_free_stack(&stack_a);
	ft_free_stack(&stack_b);
}

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
		ft_printf("KO\n");
		return (0);
	}
	ft_checker(splited);
	if (flag == 1)
		ft_free_double_pointer(splited);
}
