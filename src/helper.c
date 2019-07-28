/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdudley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 22:17:10 by bdudley           #+#    #+#             */
/*   Updated: 2019/07/28 18:37:19 by bdudley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			put_number(t_stack **a, char *str)
{
	int	number;
	int	flag;
	int	off;
	int	lim;

	number = 0;
	flag = 1;
	if (*str == '-')
	{
		flag = -1;
		str++;
	}
	off = flag == 1 ? INT_MAX : INT_MIN;
	lim = flag * (off % 10);
	off /= flag * 10;
	while (*str != '\0')
	{
		if (*str > '9' || *str < '0' || number * flag > off
			|| (flag * number == off && (*str - '0') > lim))
			error(a, NULL, NULL);
		number = number * 10 + flag * (*str - '0');
		str++;
	}
	return (number);
}

int			is_sorted_b(t_stack **a, t_stack **b, t_helper **help)
{
	t_stack		*ptr;
	int			i;

	i = 0;
	ptr = *a;
	while (i++ < (*help)->count[(*help)->i])
	{
		if (ptr->next == NULL || ptr->number < ptr->next->number)
			return (1);
		ptr = ptr->next;
	}
	(*help)->sorted_count += (*help)->count[(*help)->i];
	while ((*help)->count[(*help)->i]-- > 0)
		command_p(a, b, &(*help)->commands, "pa\n\0");
	(*help)->count[(*help)->i] = 0;
	(*help)->i--;
	return (0);
}

int			is_sorted(t_stack *a, int count)
{
	int i;

	i = 0;
	while (i++ < (count - 1))
	{
		if (a->next == NULL || a->number > a->next->number)
			return (1);
		a = a->next;
	}
	return (0);
}

void		put_stack(int argc, char *argv[], t_stack **a, t_stack **b)
{
	int	i;
	int num;

	i = 1;
	while (i < argc)
	{
		if (*argv[i] == '\0')
			error(a, NULL, NULL);
		num = put_number(a, argv[i]);
		if (exist(*b, num))
			error(a, b, NULL);
		push(b, num);
		i++;
	}
	while (*b != NULL)
	{
		push(a, (*b)->number);
		pop(b);
	}
}
