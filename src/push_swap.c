/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdudley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 22:15:52 by bdudley           #+#    #+#             */
/*   Updated: 2019/07/28 17:04:49 by bdudley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		*initialize(int count)
{
	int	*mass;
	int	i;

	i = 0;
	mass = (int *)malloc(sizeof(int) * (count));
	while (i < count)
	{
		mass[i] = 0;
		i++;
	}
	return (mass);
}

int		main(int argc, char *argv[])
{
	t_helper	*help;
	t_stack		*a;
	t_stack		*b;

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
		help->count_a = argc - 1;
		help->sorted_count = 0;
		help->i = -1;
		if (argc - 1 <= 3)
			small_sort(&a, &b, &help);
		else
			sort(&a, &b, &help);
		print_command(help->commands);
		clear(&a, &b, &help);
	}
	return (0);
}
