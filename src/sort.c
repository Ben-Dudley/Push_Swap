/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdudley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 17:35:29 by bdudley           #+#    #+#             */
/*   Updated: 2019/07/26 17:52:27 by bdudley          ###   ########.fr       */
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

void	small_sort(t_stack **a, t_stack **b, t_helper **help)
{
	if (is_sorted((*help)->count[(*help)->i]))
	{
		command_s(*a);
		ft_lstadd_back(&(*help)->commands, ft_lstnew("sa\n\0", 4));
	}
}

void	sort(t_stack **a, t_stack **b, t_helper **help)
{
	while (is_sorted(*a, (*help)->max_count) || *b != NULL)
	{
		if ((*help)->count[(*help)->i] < 3)
			small_sort(a, b, help);
		else if ()
	}

}