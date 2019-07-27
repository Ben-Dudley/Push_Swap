/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdudley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 13:04:12 by bdudley           #+#    #+#             */
/*   Updated: 2019/07/27 15:54:57 by bdudley          ###   ########.fr       */
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

void		sort(t_stack **a, t_stack **b, t_helper **help)
{
	int		copy_count;

	while ((*help)->sorted_count != (*help)->max_count)
	{
		if ((*help)->count_a < 3)
		{
			small_sort(a, b, help);
			(*help)->sorted_count += 2;
		}
		else
		{
			copy_count = (*help)->count_a;
			(*help)->count_a = (*help)->count_a - sort_a(a, b, help);
			(*help)->count[(*help)->i] = copy_count -
					(*help)->count[(*help)->i];
			(*help)->i++;
		}
	}
}
