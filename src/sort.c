/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdudley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 17:35:29 by bdudley           #+#    #+#             */
/*   Updated: 2019/08/04 20:03:23 by bdudley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		first_small_sort(t_stack **a, t_helper **help)
{
	int e1;
	int e2;
	int e3;

	e1 = (*a) ? (*a)->number : 0;
	e2 = (*a)->next ? (*a)->next->number : 0;
	e3 = (*a)->next->next ? (*a)->next->next->number : 0;
	if ((*help)->count_a == 3 && ((e1 > e2 && e1 > e3) || (e3 > e1 && e3 < e2)))
		command_r(a, &(*help)->commands, "ra\n\0");
	if ((*help)->count_a == 2 || (e1 > e2 && e1 < e3) ||
		(e3 > e1 && e3 < e2) || (e2 < e1 && e2 > e3))
		command_s(*a, &(*help)->commands, "sa\n\0");
	if ((*help)->count_a == 3 && (e2 > e1 && e2 > e3))
		command_rr(a, &(*help)->commands, "rra\n\0");
}

static void	enumeration_a(t_stack **a, t_helper **help)
{
	int e1;
	int e2;
	int e3;

	e1 = (*a)->number;
	e2 = (*a)->next->number;
	e3 = (*a)->next->next->number;
	if (e1 < e2 && e2 < e3)
		return ;
	else if (e1 < e2 && e2 > e3)
	{
		command_r(a, &(*help)->commands, "ra\n\0");
		command_s(*a, &(*help)->commands, "sa\n\0");
		command_rr(a, &(*help)->commands, "rra\n\0");
	}
	else if (e1 > e2 && e1 > e3)
	{
		command_s(*a, &(*help)->commands, "sa\n\0");
		command_r(a, &(*help)->commands, "ra\n\0");
		command_s(*a, &(*help)->commands, "sa\n\0");
		command_rr(a, &(*help)->commands, "rra\n\0");
	}
	if ((e1 < e2 && e1 > e3) || (e1 > e2 && e1 < e3) || (e1 > e2 && e2 > e3))
		command_s(*a, &(*help)->commands, "sa\n\0");
}

static void	enumeration_b(t_stack **a, t_stack **b, t_helper **help)
{
	int e1;
	int e2;
	int e3;

	e1 = (*b)->number;
	e2 = (*b)->next->number;
	e3 = (*b)->next->next->number;
	if ((e1 < e2 && e2 > e3) || !is_sorted(*b, 3))
		command_s(*b, &(*help)->commands, "sb\n\0");
	if ((e1 > e2 && e2 < e3) || (e1 < e2 && e1 < e3))
	{
		command_p(a, b, &(*help)->commands, "pa\n\0");
		command_s(*b, &(*help)->commands, "sb\n\0");
		(*help)->sorted_count += 1;
		(*help)->count[(*help)->i]--;
	}
	if (e1 < e3 && e2 < e3)
	{
		command_p(a, b, &(*help)->commands, "pa\n\0");
		command_s(*a, &(*help)->commands, "sa\n\0");
		(*help)->sorted_count += 1;
		(*help)->count[(*help)->i]--;
	}
}

void		small_sort(t_stack **a, t_stack **b, t_helper **help)
{
	if ((*help)->count_a > 0)
	{
		if ((*help)->count_a == 3)
			enumeration_a(a, help);
		else if (is_sorted(*a, (*help)->count_a))
			command_s(*a, &(*help)->commands, "sa\n\0");
		(*help)->sorted_count += (*help)->count_a;
		(*help)->count_a = 0;
	}
	if (*b && (*help)->count[(*help)->i] < 4 &&
		(*help)->count[(*help)->i] > -4)
	{
		if ((*help)->count[(*help)->i] < 0)
			rev_b(a, b, help, -(*help)->count[(*help)->i]);
		else if ((*help)->count[(*help)->i] == 3)
			enumeration_b(a, b, help);
		else if (!is_sorted(*b, (*help)->count[(*help)->i]) &&
				(*help)->count[(*help)->i] > 1)
			command_s(*b, &(*help)->commands, "sb\n\0");
		(*help)->sorted_count += (*help)->count[(*help)->i];
		while ((*help)->count[(*help)->i]-- > 0)
			command_p(a, b, &(*help)->commands, "pa\n\0");
		(*help)->count[(*help)->i] = 0;
		(*help)->i--;
	}
}
