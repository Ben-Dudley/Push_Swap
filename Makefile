# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bdudley <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/17 23:17:28 by bdudley           #+#    #+#              #
#    Updated: 2019/08/04 20:10:47 by bdudley          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_P = push_swap
NAME_C = checker
FLAGS = -g -Wall -Wextra -Werror
INC = ./inc
INC_2 = ./libft
SRCS = ./src/commands.c ./src/clear.c ./src/helper.c ./src/stack.c
SRCS_P = ./src/push_swap.c ./src/sort.c ./src/quicksort.c ./src/print_command.c ./src/merge_operation.c ./src/small_sort_reverse_b.c
SRCS_C = ./src/checker.c ./src/combine_commands.c
OBJS = $(SRCS:.c=.o)
OBJS_P = $(SRCS_P:.c=.o)
OBJS_C = $(SRCS_C:.c=.o)
LIB = ./libft/libft.a

all: $(NAME_P) $(NAME_C)

$(NAME_P): $(OBJS) $(OBJS_P)
	make -C ./libft
	gcc $(FLAGS) $(OBJS) $(OBJS_P) $(LIB) -o $(NAME_P)

$(NAME_C): $(OBJS) $(OBJS_C)
	make -C ./libft
	gcc $(FLAGS) $(OBJS) $(OBJS_C) $(LIB) -o $(NAME_C)

%.o: %.c
	gcc $(FLAGS) -c $< -o $@ -I$(INC) -I$(INC_2)

clean:
	make -C ./libft clean
	rm -f $(OBJS)
	rm -f $(OBJS_P)
	rm -f $(OBJS_C)

fclean: clean
	make -C ./libft fclean
	rm -f $(NAME_P)
	rm -f $(NAME_C)

re: fclean all
