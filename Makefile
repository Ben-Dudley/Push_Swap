# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bdudley <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/17 23:17:28 by bdudley           #+#    #+#              #
#    Updated: 2019/07/18 18:07:55 by bdudley          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_P = push_swap
NAME_C = checker
FLAGS = -Wall -Wextra -Werror
INC = ./inc
INC_2 = ./libft
SRCS = ./src/commands.c ./src/helper.c ./src/stack.c
SRCS_P = ./src/push_swap.c ./src/sort.c
SRCS_C = ./src/checker.c ./src/get_next_line.c
OBJS = $(SRCS:.c=.o)
OBJS_P = $(SRCS_P:.c=.o)
OBJS_C = $(SRCS_C:.c=.o)
LIB = ./libft/libft.a

all: $(NAME_P) $(NAME_C)

$(NAME_P): $(OBJS) $(OBJS_P)
	gcc $(FLAGS) $(OBJS) $(OBJS_P) $(LIB) -o $(NAME_P)

$(NAME_C): $(OBJS) $(OBJS_C)
	make -C ./libft
	gcc $(FLAGS) $(OBJS) $(OBJS_C) $(LIB) -o $(NAME_C)

%.o: %.c
	gcc $(FLAGS) -c $< -o $@ -I$(INC) -I$(INC_2)

clean:
	make -C ./libft clean
	rm -f $(OBJS)

fclean: clean
	make -C ./libft fclean
	rm -f $(NAME_P)

re: fclean all
