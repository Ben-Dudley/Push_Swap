# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bdudley <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/17 23:17:28 by bdudley           #+#    #+#              #
#    Updated: 2019/07/18 16:03:07 by bdudley          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_P = push_swap
NAME_C = checker
FLAGS = -Wall -Wextra -Werror
INC = inc/*
SRCS = src/*
OBJS = $(SRCS:.c=.o)
LIB = ./lib/libft/libft.a

all: $(NAME)

$(NAME): $(OBJS)
	make -C ./lib/libft
#	gcc $(FLAGS) $(OBJS) $(LIB) -o $(NAME)
	cp lib/libft/libft.a ./$(NAME)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

%.o: %.c
	gcc $(FLAGS) -c $< -o $@

clean:
	make -C ./lib/libft clean
	rm -f $(OBJS)

fclean: clean
	make -C ./lib/libft fclean
	rm -f $(NAME)

re: fclean all
