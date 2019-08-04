/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdudley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 13:56:47 by bdudley           #+#    #+#             */
/*   Updated: 2019/08/04 17:36:51 by bdudley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		reverse(const char *content, const char *content_next)
{
	if ((ft_strcmp(content, "rra\n") == 0
		&& ft_strcmp(content_next, "ra\n") == 0) ||
			(ft_strcmp(content, "ra\n") == 0
		&& ft_strcmp(content_next, "rra\n") == 0) ||
			(ft_strcmp(content, "rb\n") == 0
		&& ft_strcmp(content_next, "rrb\n") == 0) ||
			(ft_strcmp(content, "pa\n") == 0
		&& ft_strcmp(content_next, "pb\n") == 0) ||
			(ft_strcmp(content, "pb\n") == 0
		&& ft_strcmp(content_next, "pa\n") == 0) ||
			(ft_strcmp(content, "rrb\n") == 0
		&& ft_strcmp(content_next, "rb\n") == 0))
		return (1);
	return (0);
}

static void		delete_reverse_operation(t_list *commands)
{
	t_list *ptr;
	t_list *prev;

	ptr = commands;
	prev = commands;
	while (ptr != NULL && ptr->next != NULL)
	{
		if (reverse((const char *)ptr->content,
				(const char *)ptr->next->content))
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
			prev = ptr;
			ptr = ptr->next;
		}
	}
}

static void		rewrite_merge_operation(t_list *commands)
{
	t_list	*p;
	t_list	*prev;
	int		flag_1;

	prev = commands;
	while (commands != NULL && commands->next != NULL)
	{
		flag_1 = get_flag((const char *)commands->content);
		p = commands->next;
		if (flag_1 < 3)
			find_merge(flag_1, &commands, &p, &prev);
		prev = commands;
		commands = commands->next;
	}
}

void			print_command(t_list *commands)
{
	delete_reverse_operation(commands);
	rewrite_merge_operation(commands);
	while (commands != NULL)
	{
		printf("%s", (char *)commands->content);
		commands = commands->next;
	}
}
