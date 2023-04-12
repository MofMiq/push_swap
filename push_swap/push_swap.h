/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marirodr <marirodr@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 11:58:48 by marirodr          #+#    #+#             */
/*   Updated: 2023/04/11 17:13:24 by marirodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}	t_stack;

//colors
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define BLUE "\033[0;36m"
# define END "\033[0m"

//utils
int		is_digit(char c);
int		is_sign(char c);
int		cmp_number(char *s1, char *s2);

//check arguments
int		is_number(char *argv);
int		ft_ndup(char **argv);
int		ft_arg_check(char **argv);

//main

//parse
char	**ft_parse(char **argv);
void	ft_print_pointer_x2(char **argv);

//frees
void	ft_free_pointer_x2(char **argv);
void	ft_free_stack(t_stack **stack);

//fill_n_indexing
t_stack	*ft_fill_stack(char **argv);
void	ft_index_stack(t_stack *stack_a, int stack_size);

//utils_stacks
t_stack	*ft_new_stack(int value);
t_stack	*ft_get_last_node(t_stack *stack);
t_stack	*ft_stack_add_last(t_stack **stack, t_stack *new);
int		ft_stack_size(t_stack *stack);
void	ft_print_list(t_stack *stack_a);

//swap
void	ft_swap_ps(t_stack *stack);
void	ft_sa(t_stack *stack_a);
void	ft_sb(t_stack *stack_b);
void	ft_ss(t_stack *stack_a, t_stack *stack_b);

//rotate
void	ft_rotate(t_stack	**stack);
void	ft_ra(t_stack **stack_a);
void	ft_rb(t_stack **stack_b);
void	ft_rr(t_stack **stack_a, t_stack **stack_b);

#endif