/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdudley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 22:22:48 by bdudley           #+#    #+#             */
/*   Updated: 2019/07/19 20:32:52 by bdudley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		get_element(t_stack *a, int count)
{
	int	i;

	i = 0;
	while (i++ < count)
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
	int count;

	merger = 0;
	count = 0;
	while (is_sorted(*a) || count_b != 0)
	{
		//print_stack(*a, *b);
		count++;
		e_current = (*a)->number;
		e_last = get_element(*a, count_a);
		e_following = (*a)->next->number;
		if (!is_sorted(*a))
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
	printf("count = %d\n", count);
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

/**
 * TODO:
 * Реализация быстрой сортировки
 */
void	sort(t_stack **a, t_stack **b, int *count)
{
	int i;

	i = 0;
	while (is_sorted(*a) || b != NULL)
	{
		if (b == NULL)
		{
			i = 0;
			while ()
		}
		else
		{

		}
	}
}

//int i;
//int pivot;
//t_stack *ptr;
//
//pivot = get_pivot(*a, count);
//