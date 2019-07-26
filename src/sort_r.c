/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdudley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 22:22:48 by bdudley           #+#    #+#             */
/*   Updated: 2019/07/26 14:00:08 by bdudley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



void	print_command(t_list *commands)
{
	t_list *ptr;
	t_list *prev;

	ptr = commands;
	prev = commands;
	while (ptr != NULL && ptr->next != NULL)
	{
		if ((ft_strcmp((const char *)ptr->content, "rra\n") == 0
		&& ft_strcmp((const char *)ptr->next->content, "ra\n") == 0) ||
				(ft_strcmp((const char *)ptr->content, "ra\n") == 0
				 && ft_strcmp((const char *)ptr->next->content, "rra\n") == 0)||
				(ft_strcmp((const char *)ptr->content, "rb\n") == 0
				 && ft_strcmp((const char *)ptr->next->content, "rrb\n") == 0)||
				(ft_strcmp((const char *)ptr->content, "rrb\n") == 0
				 && ft_strcmp((const char *)ptr->next->content, "rb\n") == 0))
		{
			prev->next = ptr->next->next;
			delete_content(&ptr->next);
			delete_content(&ptr);
			ptr = prev;
			prev = commands;
			while (prev->next != ptr)
				prev = prev->next;

		}
		else
		{
			prev= ptr;
			ptr = ptr->next;
		}
	}
	while (commands != NULL)
	{
		printf("%s", (char *)commands->content);
		commands = commands->next;
	}
}

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
void	small_sort(t_stack **a, t_stack **b, t_helper **help, int count[2])
{
	int e_current;
	int	e_last;
	int e_following;
	int merger;

	merger = 0;
	if (count[0] == 0) {
		merger = 1;
		count[0] = count[0] ^ count[1];
		count[1] = count[1] ^ count[0];
		count[0] = count[0] ^ count[1];
	}
	while (is_sorted(*a, count[0]) || count[1] != 0)
	{
		e_current = (*a)->number;
		e_last = get_element(*a, count[0]);
		e_following = (*a)->next->number;
		if (!is_sorted(*a, count[0]))
		{
			command_p(a, b);
			count[1]--;
			count[0]++;
			if (merger == 1)
				ft_lstadd_back(&(*help)->commands, ft_lstnew("pb\n\0", 4));
			else
				ft_lstadd_back(&(*help)->commands, ft_lstnew("pa\n\0", 4));
		}
		else if (e_current < e_last && e_current < e_following && count[0] > 3)
		{
			command_p(b, a);
			count[0]--;
			count[1]++;
			if (merger == 1)
				ft_lstadd_back(&(*help)->commands, ft_lstnew("pa\n\0", 4));
			else
				ft_lstadd_back(&(*help)->commands, ft_lstnew("pb\n\0", 4));
		}
		else if (e_current > e_last && e_current > e_following)
		{
				command_r(a);
			if (merger == 1)
				ft_lstadd_back(&(*help)->commands, ft_lstnew("rb\n\0", 4));
			else
				ft_lstadd_back(&(*help)->commands, ft_lstnew("ra\n\0", 4));
		}
		else if ((e_current > e_last && e_current < e_following) || (e_current < e_last && e_current > e_following)
		|| (e_current < e_last && e_current < e_following))
		{
			if (count[1] > 1 && (*b)->number < (*b)->next->number)
			{
				command_s(*a);
				command_s(*b);
				ft_lstadd_back(&(*help)->commands,ft_lstnew("ss\n\0", 4));
			}
			else {
				command_s(*a);
				if (merger == 1)
					ft_lstadd_back(&(*help)->commands, ft_lstnew("sb\n\0", 4));
				else
					ft_lstadd_back(&(*help)->commands, ft_lstnew("sa\n\0", 4));
			}

		}
		else
		{
			command_rr(a);
			if (merger == 1)
				ft_lstadd_back(&(*help)->commands, ft_lstnew("rrb\n\0", 5));
			else
				ft_lstadd_back(&(*help)->commands, ft_lstnew("rra\n\0", 5));
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

int		sorted_a(t_stack **a, t_stack **b, t_helper **help)
{
	int count_a;
	int	pivot;
	int c_count;

	c_count = (*help)->count[(*help)->i];
	pivot = get_pivot(*a, c_count);
	count_a = 0;
	while (c_count > 0)
	{
		if ((*a)->number >= pivot)
		{
			count_a++;
			command_r(a);
			ft_lstadd_back(&(*help)->commands, ft_lstnew("ra\n\0", 4));
		}
		else
		{
			command_p(b, a);
			ft_lstadd_back(&(*help)->commands, ft_lstnew("pb\n\0", 4));
		}
		c_count--;
	}
	c_count = 0;
	while ((*help)->count[(*help)->i] != (*help)->max_count && c_count < count_a)
	{
		c_count++;
		command_rr(a);
		ft_lstadd_back(&(*help)->commands, ft_lstnew("rra\n\0", 5));
	}
	return (count_a);
}

int		sorted_b(t_stack **a, t_stack **b, t_helper **help)
{
	int	c_count;
	int count_b;
	int pivot;

	pivot = get_pivot(*b, (*help)->count[(*help)->i]);
	count_b = 0;
	c_count = (*help)->count[(*help)->i];
	while (c_count > 0)
	{
		if ((*b)->number >= pivot)
		{
			command_p(a, b);
			ft_lstadd_back(&(*help)->commands, ft_lstnew("pa\n\0", 4));
		}
		else
		{
			count_b++;
			command_r(b);
			ft_lstadd_back(&(*help)->commands, ft_lstnew("rb\n\0", 4));
		}
		c_count--;
	}
	return (count_b);
}

void	sort(t_stack **a, t_stack **b, t_helper **help)
{
	int		j;
	int		count[2];

	while (is_sorted(*a, (*help)->max_count) || *b != NULL)
	{
		if (*b == NULL)
		{
			if (!is_sorted(*a, (*help)->count[(*help)->i]))
			{
				j = 0;
				while (j <(*help)->count[(*help)->i]) {
					command_r(a);
					ft_lstadd_back(&(*help)->commands, ft_lstnew("ra\n\0", 4));
					j++;
				}
				(*help)->count[(*help)->i--]= 0;
			}
			else if ((*help)->count[(*help)->i] > 5)
			{
				(*help)->count[(*help)->i + 1] = (*help)->count[(*help)->i] - sorted_a(a, b, help);
				(*help)->count[(*help)->i] = (*help)->count[(*help)->i] - (*help)->count[(*help)->i + 1];
				(*help)->i++;
			}
			else
			{
					j = 0;
					while (j < (*help)->count[(*help)->i])
					{
						command_p(b, a);
						ft_lstadd_back(&(*help)->commands, ft_lstnew("pb\n\0", 4));
						j++;
					}
			}
		}
		else
		{
			while ((*help)->count[(*help)->i] > 5)
			{
				(*help)->count[(*help)->i + 1] = sorted_b(a, b, help);
				(*help)->count[(*help)->i] = (*help)->count[(*help)->i] - (*help)->count[(*help)->i + 1];
				(*help)->i++;
			}
			count[0] = 0;
			count[1] = (*help)->count[(*help)->i];
			small_sort(b, a, help, count);
			(*help)->count[(*help)->i--]= 0;
			while (*b != NULL)
			{
				command_p(a, b);
				command_r(a);
				ft_lstadd_back(&(*help)->commands, ft_lstnew("pa\n\0", 4));
				ft_lstadd_back(&(*help)->commands, ft_lstnew("ra\n\0", 4));
			}
		}
	}
}

