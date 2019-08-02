/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdudley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 17:35:29 by bdudley           #+#    #+#             */
/*   Updated: 2019/08/02 14:57:06 by bdudley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	enumeration_a(t_stack **a, t_helper **help)
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

void	enumeration_b(t_stack **a, t_stack **b, t_helper **help)
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

void	small_sort(t_stack **a, t_stack **b, t_helper **help)
{
	//printf("small sort\n");
	if ((*help)->count_a > 0)
	{

		//printf("small a\n");
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
	//	printf("small b\n");
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

int		get_pivot(t_stack *a, int count)
{
	t_stack	*ptr;
	int current;
	int i;
	int max;
	int min;

	i = 0;
	max = a->number;
	min = a->number;
	ptr = a;
	while (i++ < count)
	{
		if (ptr->number > max)
			max = ptr->number;
		if (ptr->number < min)
			min = ptr->number;
		ptr = ptr->next;
	}
	while (min != max)
	{
		current = min;
		ptr = a;
		i = 0;
		while (i++ < count)
		{
			if (ptr->number < max && ptr->number > current)
				current = ptr->number;

			ptr = ptr->next;
		}
		if (current == min)
			return (max);
		max = current;
		i = 0;
		ptr = a;
		while (i++ < count)
		{
			if (ptr->number > min && ptr->number < current)
				current = ptr->number;
			ptr = ptr->next;
		}
		min = current;
	}
	return (min);
}

//int		get_pivot(t_stack *a, int count)
//{
//	long	summ;
//	int		i;
//	int		result;
//
//	i = 0;
//	summ = 0;
//	while (i < count)
//	{
//		summ += a->number;
//		a = a->next;
//		i++;
//	}
//	result =  count == 0 ? 0 : summ / count;
//	result = (summ % count != 0) ? result + 1 : result;
//	return  (result);
//}

int		get_element(t_stack *a, int count)
{
	int i;

	i = 0;
	while (i++ < count)
	{
		if (!a ->next)
			return (0);
		a = a->next;
	}
	return (a->number);
}

void	rev_b(t_stack **a, t_stack **b, t_helper **help, int count_b)
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
			(count_b == 3 && e1 > e2 && e2 > e1))
		while (count_b--)
			command_rr(b, &(*help)->commands, "rrb\n\0");
	else if (count_b == 2 || (count_b == 3 && e1 < e2 && e2 < e3))
	{
		while (count_b--) {
			command_rr(b, &(*help)->commands, "rrb\n\0");
			command_p(a, b, &(*help)->commands, "pa\n\0");
		}
		(*help)->sorted_count += (*help)->count[(*help)->i];
		(*help)->count[(*help)->i] = 0;
	}
	else
	{
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
		(*help)->sorted_count += count_b - (*help)->count[(*help)->i];
	}
}