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

int			get_pivot(t_stack *a, int count)
{
	long	summ;
	int		i;
	int		result;

	i = 0;
	summ = 0;
	while (i < count)
	{
		summ += a->number;
		a = a->next;
		i++;
	}
	result = count == 0 ? 0 : summ / count;
	result = (summ % count != 0) ? result + 1 : result;
	return (result);
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
