/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdudley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 22:17:10 by bdudley           #+#    #+#             */
/*   Updated: 2019/07/17 22:27:40 by bdudley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	error(void)
{
	write(1, "Error\n", 5);
	exit(1);
}

int		put_number(char *str)
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
			error();
		number = number * 10 + flag * (*str - '0');
		str++;
	}
	return (number);
}

int		is_sorted(t_stack *a)
{
	while (a->next != NULL && a->number < a->next->number)
		a = a->next;
	if (a->next == NULL)
		return (0);
	return (1);
}
