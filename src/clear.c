/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdudley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 17:06:24 by bdudley           #+#    #+#             */
/*   Updated: 2019/08/07 17:01:04 by bdudley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		delete_content(t_list **alst)
{
	if (alst == NULL || *alst == NULL)
		return ;
	free((*alst)->content);
	(*alst)->content = NULL;
	(*alst)->content_size = 0;
	free(*alst);
	*alst = NULL;
}

void		clear(t_stack **a, t_stack **b, t_helper **help)
{
	t_list	*ptr;

	delete(a);
	delete(b);
	if (help && *help)
	{
		while ((*help)->commands)
		{
			ptr = (*help)->commands;
			(*help)->commands = (*help)->commands->next;
			delete_content(&ptr);
		}
		free((*help)->commands);
		free((*help)->count);
		free(*help);
	}
}

void		error(t_stack **a, t_stack **b, t_helper **help)
{
	clear(a, b, help);
	write (1, "Error\n", 6);
	exit(3);
}