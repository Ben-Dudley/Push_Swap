/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdudley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 22:21:50 by bdudley           #+#    #+#             */
/*   Updated: 2019/07/18 19:42:24 by bdudley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * TODO:
 * Сделать checker
 * memory leaks
 * Отладка, тесты, оптимизация
 * print_stack оставить или перенести?
 * Перенести все header в одну папку includes
 * 5 function in file ?
 * Массив указателей на комманды и и скоращенный вывод с печатью
 * Вывести quicksort в отдельный файл
 * CMake libft/Makefile (поправить Makefile в libft, пересобирается ли у меня мейк)
 * Добавить GNL в libft
 */
#ifndef PUSH_SWAP_STACK_H
# define PUSH_SWAP_STACK_H

# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <unistd.h>

typedef struct		s_stack
{
	int				number;
	struct s_stack	*next;
}					t_stack;

void				command_s(t_stack *a);
void				command_p(t_stack **a, t_stack **b);
void				command_r(t_stack **a);
void				command_rr(t_stack **a);

void				push(t_stack **a, int number);
void				pop(t_stack **a);
int					exist(t_stack *a, int number);

int					is_sorted(t_stack *a);
void				print_stack(t_stack *a, t_stack *b);
int					put_number(char *str);
void				error();

#endif
