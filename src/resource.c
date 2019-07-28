/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resource.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdudley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 16:03:31 by bdudley           #+#    #+#             */
/*   Updated: 2019/07/28 17:07:31 by bdudley          ###   ########.fr       */
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
