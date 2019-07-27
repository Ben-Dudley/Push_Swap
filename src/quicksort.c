/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdudley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 13:04:12 by bdudley           #+#    #+#             */
/*   Updated: 2019/07/27 20:02:22 by bdudley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			sort_a(t_stack **a, t_stack **b, t_helper **help)
{
	int	count_a;
	int	pivot;
	int	c_count;

	c_count = (*help)->count_a;
	pivot = get_pivot(*a, c_count);
	count_a = 0;
	while (c_count > 0)
	{
		if ((*a)->number > pivot)
		{
			count_a++;
			command_r(a, &(*help)->commands, "ra\n\0");
		}
		else
			command_p(b, a, &(*help)->commands, "pb\n\0");
		c_count--;
	}
	while ((*help)->sorted_count != 0 && c_count < count_a)
	{
		c_count++;
		command_rr(a, &(*help)->commands, "rra\n\0");
	}
	return (count_a);
}

int			sort_b(t_stack **a, t_stack **b, t_helper **help)
{
	int	c_count;
	int count_b;
	int pivot;

	pivot = get_pivot(*b, (*help)->count[(*help)->i]);
	count_b = 0;
	c_count = (*help)->count[(*help)->i];
	while (c_count > 0)
	{
		if ((*b)->number > pivot)
			command_p(a, b, &(*help)->commands, "pa\n\0");
		else
		{
			count_b++;
			command_r(b, &(*help)->commands, "rb\n\0");
		}
		c_count--;
	}
	while (c_count < count_b && (*help)->i != 0)
	{
		c_count++;
		command_rr(b, &(*help)->commands, "rrb\n\0");
	}
	return (count_b);
}

void		sort(t_stack **a, t_stack **b, t_helper **help)
{
	while (is_sorted(*a, (*help)->max_count))
	{
		if ((*help)->count_a == 0 && (*help)->count[(*help)->i] < 4)
			small_sort(a, b, help);
		else if ((*help)->count_a == 0)
		{
			(*help)->i = (*help)->i == 0 ? (*help)->i : (*help)->i--;
			(*help)->count_a = (*help)->count[(*help)->i] - sort_b(a, b, help);
			(*help)->count[(*help)->i] -= (*help)->count_a;
			(*help)->i++;

		}
		else if ((*help)->count_a < 4)
			small_sort(a, b, help);
		else
		{
			(*help)->count[(*help)->i] = (*help)->count_a - sort_a(a, b, help);
			(*help)->count_a -= (*help)->count[(*help)->i];
			(*help)->i++;
		}
	}
}
