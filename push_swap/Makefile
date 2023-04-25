# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marirodr <marirodr@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/22 13:21:44 by marirodr          #+#    #+#              #
#    Updated: 2023/04/25 13:52:58 by marirodr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= 	push_swap

CC			=	gcc

CFLAGS 		= 	-Wall -Werror -Wextra

LIBFT		= 	libft/libft.a

SRC			= 	check_arg.c utils.c main.c parsel.c frees.c \
				fill_n_indexing.c utils_stacks.c swap.c rotate.c reverse_rotate.c \
				push.c sort.c target.c cost.c move.c \

OBJT		= 	$(SRC:.c=.o)

GREEN		=		\033[0;32m
RED			=		\033[0;31m
END			=		\033[0m

all:			$(NAME)

$(NAME):	 $(OBJT)
					@make -s -C libft
					@$(CC) $(CFLAGS) $(OBJT) $(LIBFT) -o $(NAME)
					@echo "$(GREEN)Ready"
#$(LIBFT):
#				make -s -C libft

.c.o:
					@$(CC) $(CFLAGS) -c $< -o $@

clean:
				@rm -f $(OBJT)
				@echo "$(RED)Compiled objects have been removed"

fclean:			clean
				@rm -f $(NAME)
				@make fclean -s -C libft
				@echo "$(RED)Executables have been removed"

re:				fclean all

py5:	re
		python3 python_visualizer.py `ruby -e "puts (1..6).to_a.shuffle.join(' ')"`
py10:	re
		python3 python_visualizer.py `ruby -e "puts (-20..10).to_a.shuffle.join(' ')"`
py100:	re
		python3 python_visualizer.py `ruby -e "puts (1..100).to_a.shuffle.join(' ')"`
py500:	re
		python3 python_visualizer.py `ruby -e "puts (1..500).to_a.shuffle.join(' ')"`

.PHONY: all, clean, fclean, re, py5, , py10, py100, py500
