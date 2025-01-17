# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lsadikaj <lsadikaj@student.42lausanne.ch>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/16 10:32:33 by lsadikaj          #+#    #+#              #
#    Updated: 2025/01/17 11:57:20 by lsadikaj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc 
CFLAGS = -Wall -Wextra -Werror -I libft

SRC = srcs/push_swap/push_swap.c srcs/push_swap/split.c \
	srcs/push_swap/stack_init.c srcs/push_swap/stack_utils.c \
	srcs/push_swap/init_a_to_b.c srcs/push_swap/init_b_to_a.c \
	srcs/push_swap/handle_errors.c \
	srcs/commands/push.c srcs/commands/rev_rotate.c srcs/commands/rotate.c \
	srcs/commands/sort_stacks.c srcs/commands/sort_stacks_utils.c \
	srcs/commands/sort_three.c srcs/commands/swap.c 

OBJ = $(SRC:.c=.o)

LIBFT = libft/libft.a

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L libft -lft

$(LIBFT):
	make -C libft

clean:
	rm -f $(OBJ)
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean all
