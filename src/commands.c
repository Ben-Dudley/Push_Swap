/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdudley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 22:21:15 by bdudley           #+#    #+#             */
/*   Updated: 2019/07/26 13:47:02 by bdudley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	command_s(t_stack *a)
{
	if (a != NULL && a->next != NULL)
	{
		a->number = a->number ^ a->next->number;
		a->next->number = a->next->number ^ a->number;
		a->number = a->number ^ a->next->number;
	}
}

void	command_p(t_stack **a, t_stack **b)
{
	t_stack *c;

	if (*b != NULL)
	{
		c = *b;
		*b = (*b)->next;
		c->next = *a;
		*a = c;
	}
}

void	command_r(t_stack **a)
{
	t_stack *ptr;

	ptr = *a;
	if (ptr && ptr->next)
	{
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = *a;
		*a = (*a)->next;
		ptr->next->next = NULL;
	}
}

void	command_rr(t_stack **a)
{
	t_stack *ptr;
	t_stack *p;

	ptr = *a;
	if (ptr && ptr->next)
	{
		while (ptr->next->next != NULL)
			ptr = ptr->next;
		p = ptr->next;
		ptr->next = NULL;
		p->next = *a;
		*a = p;
	}
}
