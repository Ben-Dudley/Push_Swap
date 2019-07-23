/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdudley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 22:21:50 by bdudley           #+#    #+#             */
/*   Updated: 2019/07/23 21:03:36 by bdudley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * TODO:
 * memory leaks
 * Отладка, тесты, оптимизация
 * print_stack оставить или перенести?
 * 5 function in file ?
 * Массив указателей на комманды и и скоращенный вывод с печатью
 * Вывести quicksort в отдельный файл
 * CMake libft/Makefile (поправить Makefile в libft, пересобирается ли у меня мейк)
 * Добавить GNL в libft
 * На rra/ra был segmetaition, проверить не наставила ли я лишних проверок
 * Тесты, подсчитывающие количество команд
 */
#ifndef PUSH_SWAP_STACK_H
# define PUSH_SWAP_STACK_H

# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <unistd.h>
# include "libft.h"

typedef struct		s_stack
{
	int				number;
	struct s_stack	*next;
}					t_stack;

typedef struct		s_helper
{
	int				*count;
	t_list			*commands;
	int				max_count;
	int				i;
}					t_helper;

void				command_s(t_stack *a);
void				command_p(t_stack **a, t_stack **b);
void				command_r(t_stack **a);
void				command_rr(t_stack **a);

void				push(t_stack **a, int number);
void				pop(t_stack **a);
int					exist(t_stack *a, int number);
void				delete(t_stack **a);

int					is_sorted(t_stack *a, int count);
void				print_stack(t_stack *a, t_stack *b);
int					put_number(t_stack **a, char *str);
void				put_stack(int argc, char *argv[], t_stack **a, t_stack **b);
void				error(t_stack **a, t_stack **b, t_helper **help);
void				clear(t_stack **a, t_stack **b, t_helper **help);

#endif
