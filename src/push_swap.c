/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdudley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 22:15:52 by bdudley           #+#    #+#             */
/*   Updated: 2019/07/17 23:03:01 by bdudley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * TODO:
 * Разъединить 30 строк в функции
 */
int main(int argc, char *argv[])
{
	int num;
	int i;
	t_stack *a;
	t_stack *b;

	b = NULL;
	a = NULL;
	if (argc > 1)
	{
		i = 1;
		while (i < argc)
		{
			num = put_number(argv[i]);
			if (exist(b, num))
				error();
			push(&b, num);
			i++;
		}
		while (b != NULL)
		{
			push(&a, b->number);
			pop(&b);
		}
		if (i - 1 <= 5)
			small_sort(&a, &b, i - 2, 0);
		else
			sort(&a, &b, i - 2);
	}
	return (0);
}