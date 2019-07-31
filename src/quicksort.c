/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdudley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 13:04:12 by bdudley           #+#    #+#             */
/*   Updated: 2019/07/31 17:01:44 by bdudley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			rev_sort_a(t_stack **a, t_stack **b, t_helper **help, int count_a)
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
	if (count_a > 3 && (*help)->sorted_count != 0)
		count_a = rev_sort_a(a, b, help, count_a);
	else
		while ((*help)->sorted_count != 0 && c_count++ < count_a)
			command_rr(a, &(*help)->commands, "rra\n\0");
	return (count_a);
}

int			rev_sort_b(t_stack **a, t_stack **b, t_helper **help)
{
	t_stack *ptr;
	int		i;
	int		pivot;

	ptr = *b;
	i = 0;
	if ((*help)->count_b > 3 && (*help)->i != 0)
	{
		pivot = (*help)->max_count - (*help)->sorted_count -
				(*help)->count_a - (*help)->count[(*help)->i];
		while (pivot--)
			ptr = ptr->next;
		pivot = get_pivot(ptr, (*help)->count_b);
		while ((*help)->count_b-- > 0)
		{
			command_rr(a, &(*help)->commands, "rrb\n\0");
			if ((*b)->number < pivot)
				i++;
			else
				command_p(a, b, &(*help)->commands, "pa\n\0");
		}
	}
//	else
//		while (i++ < (*help)->count_b && (*help)->i != 0)
//			command_rr(b, &(*help)->commands, "rrb\n\0");
	(*help)->count_b = 0;
	return (i);
}

int			sort_b(t_stack **a, t_stack **b, t_helper **help)
{
	int	c_count;
	int count_b;
	int pivot;

	if ((*help)->count_b == 0 || (*help)->i == 0)
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
			} else
				command_p(a, b, &(*help)->commands, "pa\n\0");
		}
		(*help)->count_b = ((*help)->i > 0) ? count_b : 0;
		if (count_b > 4)
			rev_b(b, help);
	}
	else
		count_b = rev_sort_b(a, b, help);
	return (count_b);
}

void		sort(t_stack **a, t_stack **b, t_helper **help)
{
	int current;

	while (is_sorted(*a, (*help)->max_count))
	{
		if ((*help)->count_a == 0 && (*help)->count[(*help)->i] < 4)
			small_sort(a, b, help);
		else if ((*help)->count_a == 0 && is_sorted_b(a, b, help))
		{
			current = sort_b(a, b, help);
			(*help)->count_a = (*help)->count[(*help)->i] - current;
			(*help)->count[(*help)->i] -= (*help)->count_a;
		}
		else if (!is_sorted(*a, (*help)->count_a))
		{
			(*help)->sorted_count += (*help)->count_a;
			(*help)->count_a = 0;
		}
		else if ((*help)->count_a < 4)
			small_sort(a, b, help);
		else
			{
				(*help)->i++;
				if ((*help)->count_b)
					rev_b(b, help);
				current = sort_a(a, b, help);
				(*help)->count[(*help)->i] = (*help)->count_a - current;
				(*help)->count_a -= (*help)->count[(*help)->i];
			}
	}
}
