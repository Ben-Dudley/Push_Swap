/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdudley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 22:16:30 by bdudley           #+#    #+#             */
/*   Updated: 2019/07/20 19:24:29 by bdudley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	push(t_stack **a, int number)
{
	t_stack *new;

	new = (t_stack *)malloc(sizeof(t_stack));
	new->number = number;
	new->next = *a;
	*a = new;
}

void	pop(t_stack **a)
{
	t_stack *b;

	if (*a != NULL)
	{
		b = *a;
		if ((*a)->next != NULL)
			*a = (*a)->next;
		else
			*a = NULL;
		free(b);
	}
}

int		exist(t_stack *a, int number)
{
	while (a != NULL)
	{
		if (a->number == number)
			return (1);
		a = a->next;
	}
	return (0);
}

void	delete(t_stack **a)
{
	t_stack *ptr;

	if (a && *a)
	{
		while ((*a)->next != NULL)
		{
			ptr = *a;
			*a = (*a)->next;
			ptr = NULL;
			free(ptr);
		}
		free(*a);

	}
}