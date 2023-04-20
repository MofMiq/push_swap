/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marirodr <marirodr@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 11:58:48 by marirodr          #+#    #+#             */
/*   Updated: 2023/04/20 12:22:38 by marirodr         ###   ########.fr       */
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
void	ft_print_list(t_stack *stack_a);

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
t_stack	*ft_get_penultimate_node(t_stack *stack);

//sort ->reorganizar
int		ft_is_sorted(t_stack	*stack);
int		ft_highest_index(t_stack	*stack);
void	ft_decide(t_stack	**stack_a, t_stack **stack_b, int stack_size);
void	ft_sort_3(t_stack	**stack_a);
void	ft_sort_plus(t_stack **stack_a, t_stack **stack_b);
void	ft_push_until_3(t_stack **stack_a, t_stack **stack_b);

//target
void	ft_position(t_stack **stack);
int		ft_find_out_tp(stack_t **stack_a, int i_b, int i_a, int tp);
void	ft_write_target_position(t_stack **stack_a, t_stack **stack_b);

//cost
void	ft_calculate_cost(t_stack **stack_a, t_stack **stack_b);

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

//reverse_rotate
void	ft_reverse_rotate(t_stack **stack);
void	ft_rra(t_stack **stack_a);
void	ft_rrb(t_stack **stack_b);
void	ft_rrr(t_stack **stack_a, t_stack **stack_b);

//push
void	ft_push(t_stack **src, t_stack **dst);
void	ft_pa(t_stack	**stack_a, t_stack **stack_b);
void	ft_pb(t_stack	**stack_a, t_stack **stack_b);

#endif