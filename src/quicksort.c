/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdudley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 13:04:12 by bdudley           #+#    #+#             */
/*   Updated: 2019/08/04 20:06:14 by bdudley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		rev_sort_a(t_stack **a, t_stack **b,
				t_helper **help, int count_a)
{
	t_stack *ptr;
	int		i;
	int		pivot;

	ptr = *a;
	i = 0;
	(*help)->count[(*help)->i++] = (*help)->count_a - count_a;
	(*help)->count_a = count_a;
	while (i++ < (*help)->sorted_count)
		ptr = ptr->next;
	pivot = get_pivot(ptr, count_a);
	i = 0;
	while (count_a > 0)
	{
		command_rr(a, &(*help)->commands, "rra\n\0");
		if ((*a)->number > pivot)
			i++;
		else
			command_p(b, a, &(*help)->commands, "pb\n\0");
		count_a--;
	}
	return (i);
}

static int		sort_a(t_stack **a, t_stack **b, t_helper **help)
{
	int	count_a;
	int	pivot;
	int	c_count;

	(*help)->i++;
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
	if (count_a > 3 && (*help)->sorted_count != 0)
		count_a = rev_sort_a(a, b, help, count_a);
	else
		while ((*help)->sorted_count != 0 && c_count++ < count_a)
			command_rr(a, &(*help)->commands, "rra\n\0");
	return (count_a);
}

static void		rev_sort_b(t_stack **a, t_stack **b, t_helper **help, int i)
{
	t_stack *ptr;
	int		pivot;
	int		c_count;

	ptr = *b;
	if ((*help)->count[(*help)->i] < -3)
	{
		c_count = (*help)->max_count - (*help)->sorted_count -
			(*help)->count_a + (*help)->count[(*help)->i];
		while (c_count--)
			ptr = ptr->next;
		pivot = get_pivot(ptr, -(*help)->count[(*help)->i]);
		c_count = (-1) * ((*help)->count[(*help)->i]);
		while (c_count-- > 0)
		{
			command_rr(b, &(*help)->commands, "rrb\n\0");
			if ((*b)->number < pivot)
				i++;
			else
				command_p(a, b, &(*help)->commands, "pa\n\0");
		}
		(*help)->count_a = (-1) * (*help)->count[(*help)->i] - i;
		(*help)->count[(*help)->i] = i;
	}
}

static void		sort_b(t_stack **a, t_stack **b, t_helper **help)
{
	int	c_count;
	int count_b;
	int pivot;

	if ((*help)->count[(*help)->i] > 0)
	{
		pivot = get_pivot(*b, (*help)->count[(*help)->i]);
		count_b = 0;
		c_count = (*help)->count[(*help)->i];
		while (c_count-- > 0)
		{
			if ((*b)->number < pivot)
			{
				count_b++;
				command_r(b, &(*help)->commands, "rb\n\0");
			}
			else
				command_p(a, b, &(*help)->commands, "pa\n\0");
		}
		(*help)->count_a = (*help)->count[(*help)->i] - count_b;
		(*help)->count[(*help)->i] = ((*help)->i > 0) ? -count_b : count_b;
	}
	else
		rev_sort_b(a, b, help, 0);
}

void			sort(t_stack **a, t_stack **b, t_helper **help)
{
	int current;

	while (is_sorted(*a, (*help)->max_count))
	{
		if ((*help)->count_a == 0 && (*help)->count[(*help)->i] < 4
		&& (*help)->count[(*help)->i] > -4)
			small_sort(a, b, help);
		else if ((*help)->count_a == 0)
			sort_b(a, b, help);
		else if (!is_sorted(*a, (*help)->count_a))
		{
			(*help)->sorted_count += (*help)->count_a;
			(*help)->count_a = 0;
		}
		else if ((*help)->sorted_count == 0 && (*help)->count_a < 4)
			first_small_sort(a, help);
		else if ((*help)->count_a < 4)
			small_sort(a, b, help);
		else
		{
			current = sort_a(a, b, help);
			(*help)->count[(*help)->i] = (*help)->count_a - current;
			(*help)->count_a -= (*help)->count[(*help)->i];
		}
	}
}
