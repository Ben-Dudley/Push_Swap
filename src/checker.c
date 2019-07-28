/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdudley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 22:23:25 by bdudley           #+#    #+#             */
/*   Updated: 2019/07/26 15:57:19 by bdudley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		check_command(t_stack **a, t_stack **b, char *command)
{
	if (ft_strcmp("ra", command) == 0)
		command_r(a, NULL, NULL);
	else if (ft_strcmp("rb", command) == 0)
		command_r(b, NULL, NULL);
	else if (ft_strcmp("rr", command) == 0)
		command_r_r(a, b, NULL, NULL);
	else if (ft_strcmp("pa", command) == 0)
		command_p(a, b, NULL, NULL);
	else if (ft_strcmp("pb", command) == 0)
		command_p(b, a, NULL, NULL);
	else if (ft_strcmp("rra", command) == 0)
		command_rr(a, NULL, NULL);
	else if (ft_strcmp("rrb", command) == 0)
		command_rr(b, NULL, NULL);
	else if (ft_strcmp("rrr", command) == 0)
		command_rrr(a, b, NULL, NULL);
	else if (ft_strcmp("sa", command) == 0)
		command_s(*a, NULL, NULL);
	else if (ft_strcmp("sb", command) == 0)
		command_s(*b, NULL, NULL);
	else if (ft_strcmp("ss", command) == 0)
		command_ss(a, b, NULL, NULL);
	else
		error(a, b, NULL);
}

int				main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;
	char	*command;

	b = NULL;
	a = NULL;
	if (argc > 1)
	{
		put_stack(argc, argv, &a, &b);
		while (get_next_line(0, &command) > 0)
			check_command(&a, &b, command);
		if (!is_sorted(a, argc - 2) && b == NULL)
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
		clear(&a, &b, NULL);
	}
	return (0);
}
