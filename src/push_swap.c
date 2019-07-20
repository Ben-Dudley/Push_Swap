/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdudley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 22:15:52 by bdudley           #+#    #+#             */
/*   Updated: 2019/07/20 19:37:32 by bdudley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		*initialize(int count)
{
	int	*mass;
	int	i;

	i = 0;
	mass = (int *)malloc(sizeof(int)* (count));
	while (i < count)
	{
		mass[count] = 0;
		i++;
	}
	mass[0] = count;
	return (mass);
}

/**
 * TODO:
 * Разъединить 30 строк в функции
 * Применить алгоритм нахождения count для массива, через деление
 * Добавить очистку памяти массива и стека
 */
int main(int argc, char *argv[])
{
	int 	num;
	int 	i;
	int		*count;
	t_stack *a;
	t_stack *b;

	b = NULL;
	a = NULL;
	if (argc > 1)
	{
		i = 1;
		while (i < argc)
		{
			num = put_number(&a, argv[i]);
			if (exist(b, num))
				error(&a, &b, &count);
			push(&b, num);
			i++;
		}
		while (b != NULL)
		{
			push(&a, b->number);
			pop(&b);
		}
		count = initialize(i - 1);
		if (i - 1 <= 5)
			small_sort(&a, &b, i - 2, 0);
		else
			sort(&a, &b, count);
		free(count);
		delete(&a);
		delete(&b);
	}
	return (0);
}