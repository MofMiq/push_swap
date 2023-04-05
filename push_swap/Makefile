# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marirodr <marirodr@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/22 13:21:44 by marirodr          #+#    #+#              #
#    Updated: 2023/04/05 17:38:53 by marirodr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= 	push_swap

CC			=	gcc

CFLAGS 		= 	-Wall -Werror -Wextra

LIBFT		= 	libft/libft.a

SRC			= 	check_arg.c utils.c main.c parsel.c \

OBJT		= 	$(SRC:.c=.o)

all:			$(NAME)

$(NAME):	 $(OBJT)
					make -s -C libft
					$(CC) $(CFLAGS) $(OBJT) $(LIBFT) -o $(NAME)
					@echo "Ready"
#$(LIBFT):
#				make -s -C libft

.c.o:
					$(CC) $(CFLAGS) -c $< -o $@

clean:
				rm -f $(OBJT)
				@echo "Compiled objects have been removed"

fclean:			clean
				rm -f $(NAME)
				make fclean -s -C libft
				@echo "Executables have been removed"

re:				fclean all

py:	all
		python3 python_visualizer.py `ruby -e "puts (-50..50).to_a.shuffle.join(' ')"

.PHONY: all, clean, fclean, re, py
