/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marirodr <marirodr@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 11:58:48 by marirodr          #+#    #+#             */
/*   Updated: 2023/04/05 17:45:43 by marirodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>

typedef struct s_stack
{
	int				value;
	int				i;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}	t_stack;

//utils
int		is_digit(char c);
int		is_sign(char c);
int		cmp_number(char *s1, char *s2);

//check arguments
int		is_number(char *argv);
int		ndup(char **argv);
int		ft_arg_check(char **argv);

//main

//parse
char	**ft_parse(char **argv);

#endif