/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdudley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 22:23:25 by bdudley           #+#    #+#             */
/*   Updated: 2019/07/18 18:09:34 by bdudley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	check_sort(t_stack **a, t_stack **b)
{
	if (*a == *b)
		return (1);
	return(0);
}

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
		if (check_sort(&a, &b))
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);

	}
	return (0);
}