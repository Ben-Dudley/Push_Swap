/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resource.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdudley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 16:03:31 by bdudley           #+#    #+#             */
/*   Updated: 2019/08/02 14:27:07 by bdudley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *a, t_stack *b)
{
	if (a)
	{
		printf("Stack a:");
		while (a->next)
		{
			printf(" %d", a->number);
			a = a->next;
		}
		printf(" %d\n", a->number);
	}
	else
		printf("Stack a = NULL\n");
	if (b)
	{
		printf("Stack b:");
		while (b->next)
		{
			printf(" %d", b->number);
			b = b->next;
		}
		printf(" %d\n", b->number);
	}
	else
		printf("Stack b = NULL\n");
}

void				first_small_sort(t_stack **a, t_helper **help)
{
	int e1;
	int e2;
	int e3;

	e1 = (*a) ? (*a)->number : 0;
	e2 = (*a)->next ? (*a)->next->number : 0;
	e3 = (*a)->next->next ? (*a)->next->next->number : 0;
	if ((*help)->count_a == 3 && ((e1 > e2 && e1 > e3) || (e3 > e1 && e3 < e2)))
		command_r(a, &(*help)->commands, "ra\n\0");
	if ((*help)->count_a == 2 || (e1 > e2 && e1 < e3) || (e3 > e1 && e3 < e2) || (e2 < e1 && e2 > e3))
		command_s(*a, &(*help)->commands, "sa\n\0");
	if ((*help)->count_a == 3 && (e2 > e1 && e2 > e3))
		command_rr(a, &(*help)->commands, "rra\n\0");
}
