/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdudley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 22:17:10 by bdudley           #+#    #+#             */
/*   Updated: 2019/07/23 21:37:59 by bdudley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

/**
 * TODO:
 * добавить сюда *commands
 * была утечка в 16 байт
 */
void	clear(t_stack **a, t_stack **b, t_helper **help)
{
	delete(a);
	delete(b);
	if (help && *help)
	{
		if ((*help)->count)
			free((*help)->count);
		*help = NULL;
	}
}

void	error(t_stack **a, t_stack **b, t_helper **help)
{
	clear(a, b, help);
	printf("Error\n");
	exit(1);
}

int		put_number(t_stack **a, char *str)
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

int		is_sorted(t_stack *a, int count)
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
