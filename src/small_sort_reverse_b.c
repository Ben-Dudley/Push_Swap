/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort_reverse_b.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdudley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 19:52:33 by bdudley           #+#    #+#             */
/*   Updated: 2019/08/04 19:52:53 by bdudley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		get_element(t_stack *a, int count)
{
	int i;

	i = 0;
	while (i++ < count)
	{
		if (!a->next)
			return (0);
		a = a->next;
	}
	return (a->number);
}

static void		reverse_b(t_stack **a, t_stack **b, t_helper **help, int count)
{
	int e1;
	int e2;
	int e3;

	e1 = get_element(*b, count);
	e2 = get_element(*b, count + 1);
	e3 = get_element(*b, count + 2);
	command_rr(b, &(*help)->commands, "rrb\n\0");
	if (e1 > e2 && e1 < e3)
		command_p(a, b, &(*help)->commands, "pa\n\0");
	command_rr(b, &(*help)->commands, "rrb\n\0");
	if ((e1 < e2 && e1 > e3) || (e3 > e1 && e3 < e2))
		command_p(a, b, &(*help)->commands, "pa\n\0");
	else if (e3 > e2 && e3 < e1)
		command_s(*b, &(*help)->commands, "sb\n\0");
	if (e3 > e1 && e3 < e2)
		command_p(a, b, &(*help)->commands, "pa\n\0");
	command_rr(b, &(*help)->commands, "rrb\n\0");
	if (e3 > e1 && e3 < e2)
		(*help)->count[(*help)->i] = 1;
	else if ((e1 > e2 && e1 < e3) || (e1 < e2 && e1 > e3))
		(*help)->count[(*help)->i] = 2;
	(*help)->sorted_count += 3 - (*help)->count[(*help)->i];
}

static void		rever_b(t_stack **a, t_stack **b, t_helper **help, int count_b)
{
	while (count_b--)
	{
		command_rr(b, &(*help)->commands, "rrb\n\0");
		command_p(a, b, &(*help)->commands, "pa\n\0");
	}
	(*help)->count[(*help)->i] *= -1;
	(*help)->sorted_count -= (*help)->count[(*help)->i];
	(*help)->count[(*help)->i] = 0;
}

void			rev_b(t_stack **a, t_stack **b, t_helper **help, int count_b)
{
	int e1;
	int e2;
	int e3;
	int count;

	(*help)->count[(*help)->i] *= -1;
	count = (*help)->max_count - (*help)->sorted_count -
			(*help)->count_a - (*help)->count[(*help)->i];
	e1 = get_element(*b, count);
	e2 = get_element(*b, count + 1);
	e3 = get_element(*b, count + 2);
	if (count_b == 1 || (count_b == 2 && e1 > e2) ||
		(count_b == 3 && e1 > e2 && e2 > e3))
		while (count_b--)
			command_rr(b, &(*help)->commands, "rrb\n\0");
	else if (count_b == 2 || (count_b == 3 && e1 < e2 && e2 < e3))
		rever_b(a, b, help, count_b);
	else
		reverse_b(a, b, help, count);
}
