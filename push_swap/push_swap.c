//
// Created by Ben Dudley on 2019-07-08.
//

#include "push_swap.h"

static void	error()
{
	write(1, "Error\n", 5);
	exit(1);
}

static int 	put_number(char *str)
{
	int number;
	int flag;
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
	lim = flag*(off % 10);
	off /= flag * 10;
	while (*str != '\0')
	{
		if (*str > '9' || *str < '0' || number * flag > off || (flag * number == off && (*str - '0') > lim))
				error();
		number = number * 10 + flag * (*str - '0');
		str++;
	}
	return (number);
}

int main(int argc, char *argv[])
{
	int num;
	int i;
	t_stack *a;
	t_stack *b;

	b = NULL;
	a = NULL;
	if (argc > 1)
	{
		i = 1;
		while (i < argc)
		{
			num = put_number(argv[i]);
			if (exist(b, num))
				error();
			push(&b, num);
			i++;
		}
		while (b != NULL)
		{
			push(&a, b->number);
			pop(&b);
		}

	}
	return (0);
}