/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdudley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 17:35:29 by bdudley           #+#    #+#             */
/*   Updated: 2019/07/27 18:24:53 by bdudley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		get_element(t_stack *a, int count)
{
	int	i;

	i = 0;
	while (i++ < count - 1)
		a = a->next;
	return (a->number);
}

void	small_sort(t_stack **a, t_stack **b, t_helper **help)
{
	if ((*help)->count_a > 0)
	{
		if (is_sorted(*a, (*help)->count_a))
			command_s(*a, &(*help)->commands, "sa\n\0");
		(*help)->sorted_count += (*help)->count_a;
		(*help)->count_a = 0;
	}
	if ((*help)->count[(*help)->i] < 3)
	{
		if (!is_sorted(*b, (*help)->count[(*help)->i]))
			command_s(*b, &(*help)->commands, "sb\n\0");
		(*help)->sorted_count += (*help)->count[(*help)->i];
		while ((*help)->count[(*help)->i]-- > 0)
			command_p(a, b, &(*help)->commands, "pa\n\0");
		(*help)->count[(*help)->i--] = 0;
	}
}

int		get_pivot(t_stack *a, int count)
{
	int e_medium;
	int e_last;
	int	e_first;

	e_first = a->number;
	e_last = get_element(a, count);
	e_medium = get_element(a, count / 2);
	if (e_first > e_last)
	{
		if (e_first < e_medium)
			return (e_first);
		return (e_last > e_medium ? e_last : e_medium);
	}
	if (e_last < e_medium)
		return (e_last);
	return (e_first > e_medium ? e_first : e_medium);
}
