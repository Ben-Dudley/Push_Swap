/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdudley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 22:22:48 by bdudley           #+#    #+#             */
/*   Updated: 2019/07/20 18:22:22 by bdudley          ###   ########.fr       */
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

/**
 * TODO:
 * Функция содержит больше 30 строк
 */
void	small_sort(t_stack **a, t_stack **b, int count_a, int count_b)
{
	int e_current;
	int	e_last;
	int e_following;
	int merger;

	merger = 0;
	while (is_sorted(*a, count_a) || count_b != 0)
	{
		e_current = (*a)->number;
		e_last = get_element(*a, count_a);
		e_following = (*a)->next->number;
		if (!is_sorted(*a, count_a))
		{
			command_p(a, b);
			count_b--;
			count_a++;
			printf("pa\n");
		}
		else if (e_current < e_last && e_current < e_following && count_a >= 3)
		{
			command_p(b, a);
			count_a--;
			count_b++;
			merger = (count_b > 1 && (*b)->number < (*b)->next->number) ? 1 : 0;
			printf("pb\n");
		}
		else if (e_current > e_last && e_current > e_following)
		{
			if (merger)
			{
				command_r(a);
				command_r(b);
				merger = 0;
				printf("rr\n");
			}
			else {
				command_r(a);
				printf("ra\n");
			}
		}
		else if ((e_current > e_last && e_current < e_following) || (e_current < e_last && e_current > e_following))
		{
			if (merger)
			{
				command_s(*a);
				command_s(*b);
				merger = 0;
				printf("ss\n");
			}
			else {
				command_s(*a);
				printf("sa\n");
			}

		}
		else
		{
			command_rr(a);
			printf("rra\n");
		}
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

int		sorted_a(t_stack **a, t_stack **b, int count)
{
	int count_a;
	int	pivot;

	pivot = get_pivot(*a, count);
	count_a = 0;
	while (count > 0)
	{
		if ((*a)->number >= pivot)
		{
			count_a++;
			command_r(a);
			printf("ra\n");
		}
		else
		{
			command_p(b, a);
			printf("pb\n");
		}
		count--;
	}
	return (count_a);
}

int		sorted_b(t_stack **a, t_stack **b, int count)
{
	int count_b;
	int pivot;

	pivot = get_pivot(*b, count);
	count_b = 0;
	while (count > 0)
	{
		if ((*b)->number >= pivot)
		{
			command_p(a, b);
			printf("pa\n");
		}
		else
		{
			count_b++;
			command_r(b);
			printf("rb\n");
		}
		count--;
	}
	return (count_b);
}
/**
 * TODO:
 * Реализация быстрой сортировки
 */
void	sort(t_stack **a, t_stack **b, int *count)
{
	int i;
	int max_count;

	i = 0;
	max_count = *count;
//	print_stack(*a, *b);
	while (is_sorted(*a, max_count) || *b != NULL)
	{
		//printf(" i = %d and count = %d\n", i, count[i]);
		if (*b == NULL)
		{
			if (count[i] > 5)
			{
				count[i + 1] = count[i] - sorted_a(a, b, count[i]);
				count[i] = count[i] - count[i + 1];
				i++;
			}
			else
			{
				small_sort(a, b, count[i], 0);
				while (count[i] > 0)
				{
					command_r(a);
					printf("ra\n");
					count[i]--;
				}
				i--;
			}
		}
		else
		{
			while (count[i] > 5)
			{
				count[i + 1] = sorted_b(a, b, count[i]);
				count[i] = count[i] - count[i + 1];
				i++;
			}
			small_sort(b, a, count[i], 0);
			count[i] = 0;
			i--;
			while (*b != NULL)
			{
				command_p(a, b);
				command_r(a);
				printf("pa\nra\n");
			}
	//		print_stack(*a, *b);
		}
	}
}

