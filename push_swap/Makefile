# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marirodr <marirodr@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/22 13:21:44 by marirodr          #+#    #+#              #
#    Updated: 2023/05/04 11:04:56 by marirodr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= 	push_swap

BONUS		=	checker

CC			=	gcc

CFLAGS 		= 	-g -Wall -Werror -Wextra

LIBFT		= 	libft/libft.a

SRC			= 	push_swap.c check_arg.c utils.c parsel.c frees.c \
				fill_n_indexing.c utils_stacks.c swap.c rotate.c reverse_rotate.c \
				push.c sort.c target.c cost.c move.c \

OBJT		= 	$(SRC:.c=.o)

SRCBONUS	=	checker.c check_arg.c utils.c parsel.c frees.c \
				fill_n_indexing.c utils_stacks.c swap.c rotate.c reverse_rotate.c \
				push.c sort.c target.c cost.c move.c \

BONUS_OBJ	=	$(SRCBONUS:.c=.o)

GREEN		=		\033[0;32m
RED			=		\033[0;31m
END			=		\033[0m

all:			$(NAME)

$(NAME):	 $(OBJT)
					@make -s -C libft
					@$(CC) $(CFLAGS) $(OBJT) $(LIBFT) -o $(NAME)
					@echo "$(GREEN)Ready"

$(BONUS):	$(BONUS_OBJ)
					@make -s -C libft
					@$(CC) $(CFLAGS) $(BONUS_OBJ) $(LIBFT) -o $(BONUS)
					@echo "$(GREEN) Checker ready"

.c.o:
					@$(CC) $(CFLAGS) -c $< -o $@

bonus: $(BONUS)

clean:
				@rm -f $(OBJT)
				@rm -f $(BONUS_OBJ)
				@echo "$(RED)Compiled objects have been removed"

fclean:			clean
				@rm -f $(NAME) $(BONUS)
				@make fclean -s -C libft
				@echo "$(RED)Executables have been removed"

re:				fclean all

py3:	re
		python3 python_visualizer.py `ruby -e "puts (1..3).to_a.shuffle.join(' ')"`
py5:	re
		python3 python_visualizer.py `ruby -e "puts (1..5).to_a.shuffle.join(' ')"`
py10:	re
		python3 python_visualizer.py `ruby -e "puts (1..10).to_a.shuffle.join(' ')"`
py100:	re
		python3 python_visualizer.py `ruby -e "puts (1..100).to_a.shuffle.join(' ')"`
py500:	re
		python3 python_visualizer.py `ruby -e "puts (1..500).to_a.shuffle.join(' ')"`

.PHONY: all, clean, fclean, re, py3, py5, py10, py100, py500, bonus
