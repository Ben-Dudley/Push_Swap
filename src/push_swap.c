/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdudley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 22:15:52 by bdudley           #+#    #+#             */
/*   Updated: 2019/07/24 17:14:49 by bdudley          ###   ########.fr       */
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
		mass[i] = 0;
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
	t_helper	*help;
	t_stack 	*a;
	t_stack 	*b;
	int			count[2];

	b = NULL;
	a = NULL;
	help = NULL;
	if (argc > 1)
	{
		put_stack(argc, argv, &a, &b);
		help = (t_helper *)malloc(sizeof(t_helper));
		help->count = initialize(argc - 1);
		help->commands = NULL;
		help->max_count = argc - 1;
		help->i = 0;
		count[0] = argc - 1;
		count[1] = 0;
		if (argc - 1 <= 5)
			small_sort(&a, &b, &help, count);
		else
			sort(&a, &b, &help);
		print_command(help->commands);
//		print_stack(a, b);
		clear(&a, &b, &help);
	}
	return (0);
}