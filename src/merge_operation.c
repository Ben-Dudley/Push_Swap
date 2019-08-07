/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_operation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdudley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 16:30:19 by bdudley           #+#    #+#             */
/*   Updated: 2019/08/05 19:46:33 by bdudley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		merge(const char *content,
						const char *content_next, t_list **ptr)
{
	if ((!ft_strcmp(content, "rra\n") && !ft_strcmp(content_next, "rrb\n"))
		|| (!ft_strcmp(content, "rrb\n") && !ft_strcmp(content_next, "rra\n")))
	{
		free((*ptr)->content);
		(*ptr)->content = ft_strdup("rrr\n\0");
	}
	else if ((!ft_strcmp(content, "sa\n") && !ft_strcmp(content_next, "sb\n"))
		|| (!ft_strcmp(content, "sb\n") && !ft_strcmp(content_next, "sa\n")))
	{
		free((*ptr)->content);
		(*ptr)->content = ft_strdup("ss\n\0");
	}
	else if ((!ft_strcmp(content, "rb\n") && !ft_strcmp(content_next, "ra\n"))
		|| (!ft_strcmp(content, "ra\n") && !ft_strcmp(content_next, "rb\n")))
	{
		free((*ptr)->content);
		(*ptr)->content = ft_strdup("rr\n\0");
	}
	else
		return (0);
	return (1);
}

int				get_flag(const char *content)
{
	if (!ft_strcmp(content, "rra\n") ||
		!ft_strcmp(content, "ra\n") || !ft_strcmp(content, "sa\n"))
		return (1);
	if (!ft_strcmp(content, "rrb\n") ||
		!ft_strcmp(content, "rb\n") || !ft_strcmp(content, "sb\n"))
		return (2);
	return (3);
}

static void		rewrite_in_beginning(t_list **commands,
				t_list **p, t_list **prev)
{
	if (merge((const char *)(*commands)->content,
			(const char *)(*p)->content, commands))
	{
		(*prev)->next = (*p)->next;
		delete_content(p);
		*p = *prev;
	}
}

static void		rewrite_to_end(t_list **commands, t_list **p, t_list **prev)
{
	if (merge((const char *)(*commands)->content,
			(const char *)(*p)->content, p))
	{
		(*prev)->next = (*commands)->next;
		delete_content(commands);
		*commands = *prev;
	}
}

void			find_merge(int flag_1, t_list **commands,
				t_list **p, t_list **prev)
{
	int		flag;
	t_list	*pr;

	pr = *commands;
	flag = 0;
	flag = (get_flag((const char *)(*p)->content) - flag == 0) ?
			flag : get_flag((const char *)(*p)->content) + flag;
	while ((*p) && (flag < 3))
	{
		if (flag == flag_1)
			rewrite_in_beginning(commands, p, &pr);
		else
			rewrite_to_end(commands, p, prev);
		flag = (get_flag((const char *)(*p)->content) - flag == 0) ?
			flag : get_flag((const char *)(*p)->content) + flag;
		pr = *p;
		*p = (*p)->next;
	}
}
