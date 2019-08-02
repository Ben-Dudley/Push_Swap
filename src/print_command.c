/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdudley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 13:56:47 by bdudley           #+#    #+#             */
/*   Updated: 2019/08/02 19:33:15 by bdudley          ###   ########.fr       */
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
	if ((ft_strcmp(content, "rra\n") == 0 ||
	ft_strcmp(content, "ra\n") == 0) || ft_strcmp(content, "sa\n") == 0)
		return (1);
	if ((ft_strcmp(content, "rrb\n") == 0 ||
		 ft_strcmp(content, "rb\n") == 0) || ft_strcmp(content, "sb\n") == 0)
		return (2);
	if ((ft_strcmp(content, "rrr\n") == 0 ||
		 ft_strcmp(content, "rr\n") == 0) || ft_strcmp(content, "ss\n") == 0||
		 ft_strcmp(content, "pa\n") == 0 || ft_strcmp(content, "pb\n") == 0)
		return (3);
	return (3);
}

static void		rewrite_merge_operation(t_list *commands)
{
	t_list *p;
	t_list *prev;
	t_list *pr;
	int flag_1;
	int flag;

	prev = commands;
	while (commands != NULL && commands->next != NULL)
	{
		flag_1 = get_flag((const char *)commands->content);
		p = commands->next;
		flag = 0;
		if (flag_1 < 3)
		{
			pr = commands;
			flag = (get_flag((const char *) p->content) - flag == 0) ?
				   flag : get_flag((const char *) p->content + flag);
			while (p && (flag < 3))
			{
				if (flag == flag_1)
				{

					if (merge((const char *) commands->content,
							  (const char *) p->content, &commands)) {
						pr->next = p->next;
						delete_content(&p);
						p = pr;
					}
				}
				else if (merge((const char *) commands->content,
								 (const char *) p->content, &p))
				{
					prev->next = commands->next;
					delete_content(&commands);
					commands = prev;
				}
				flag = (get_flag((const char *) p->content) - flag == 0) ?
					   flag : get_flag((const char *) p->content + flag);
				pr = p;
				p = p->next;
			}
		}
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
