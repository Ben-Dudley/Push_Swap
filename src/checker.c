/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdudley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 22:23:25 by bdudley           #+#    #+#             */
/*   Updated: 2019/07/23 20:23:43 by bdudley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/**
 * TODO:
 * Подумать над объединением(указатели на функции?)
 */
void		check_sort(t_stack **a, t_stack **b)
{
	char *command;

	while (get_next_line(0, &command) > 0)
	{
		if (ft_strcmp("ra", command) == 0)
			command_r(a);
		else if (ft_strcmp("rb", command) == 0)
			command_r(b);
		else if (ft_strcmp("rr", command) == 0)
		{
			command_r(a);
			command_r(b);
		}
		else if (ft_strcmp("pa", command) == 0)
			command_p(a, b);
		else if (ft_strcmp("pb", command) == 0)
			command_p(b, a);
		else if (ft_strcmp("rra", command) == 0)
			command_rr(a);
		else if (ft_strcmp("rrb", command) == 0)
			command_rr(b);
		else if (ft_strcmp("rrr", command) == 0)
		{
			command_rr(a);
			command_rr(b);
		}
		else if (ft_strcmp("sa", command) == 0)
			command_s(*a);
		else if (ft_strcmp("sb", command) == 0)
			command_s(*b);
		else if (ft_strcmp("ss", command) == 0)
		{
			command_s(*a);
			command_s(*b);
		}
		else
			error(a, b, NULL);
	}
}

int			main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;

	b = NULL;
	a = NULL;
	if (argc > 1)
	{
		put_stack(argc, argv, &a, &b);
		check_sort(&a, &b);
		if (!is_sorted(a, argc - 2) && b == NULL)
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
		clear(&a, &b, NULL);
	}
	return (0);
}
