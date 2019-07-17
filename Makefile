# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bdudley <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/17 23:17:28 by bdudley           #+#    #+#              #
#    Updated: 2019/07/17 23:32:13 by bdudley          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_P = push_swap
NAME_C = checker
FLAGS = -Wall -Wextra -Werror
INC = checker/checker.h commands/stack.h push_swap/push_swap.h
SRCS = checker/checker.c commands/commands.c commands/stack.c push_swap/push_swap.c push_swap/sort.c commands/helper.c

OBJS = $(SRCS:.c=.o)

all: $(NAME_P)

$(NAME_P): $(OBJS)
	gcc $(FLAGS) $(OBJS) -I $(INC) -o $(NAME_P)

%.o: %.c
	gcc $(FLAGS) -c $< -o $@

clean:
#	make -C ./lib/libft clean
	rm -f $(OBJS)

fclean: clean
#	make -C ./lib/libft fclean
	rm -f $(NAME_P)

re: fclean all
