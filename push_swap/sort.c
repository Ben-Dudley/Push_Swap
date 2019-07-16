//
// Created by Ben Dudley on 2019-07-09.
//


//sort - обработка ошибок на пустой стек
//объединение таких команд, как sa sb в ss

#include "push_swap.h"

int		get_last_element(t_stack *a)
{
	while (a->next != NULL)
		a = a->next;
	return (a->number);
}

void	sort_a(t_stack **a, t_stack **b)
{
	int last;
	int	current;
	int	following;
	int	last_b;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	current = (*a)->number;
	following = (*a)->next->number;
	last = get_last_element(*a);
	if (*b != NULL) {
		last_b = get_last_element(*b);
		while ((last_b < current && last_b > last) || (last_b > current && last > last_b)) {
			command_p(a, b);
			write(1, "pa\n", 3);
		}
	}
	if (current > following && current > last)
	{
		command_s(*a);
		write(1, "sa\n", 3);
	}
	else if (current < last && current < following)
	{
		command_p(b, a);
		write(1, "pb\n", 3);
		sort_b(a, b);
	}
	else if (current > following)
	{
		command_r(a);
		write(1, "ra\n", 3);
	}
	else
	{
		command_rr(a);
		write(1, "rra\n", 4);
	}
}

void	sort_b(t_stack **a, t_stack **b)
{
	t_stack *last;
	t_stack *current;
	t_stack *following;

	if (*b == NULL || (*b)->next == NULL)
		return ;
	current = *b;
	following = (*b)->next;
	last = get_last_element(*b);
	if (current < following && current < last)
	{
		command_s(*b);
		write(1, "sb\n", 3);
	}
	else if (current < following && current > last)
	{
		command_r(b);
		write(1, "rb\n", 3);
	}
	else if (current > following && last > current)
	{
		command_rr(b);
		write(1, "rrb\n", 4);
	}
}