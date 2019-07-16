//
// Created by Ben Dudley on 2019-07-08.
//

#include "stack.h"

void	command_s(t_stack *a)
{
	if (a != NULL && a->next != NULL)
	{
		a->number = a->number ^ a->next->number;
		a->next->number = a->next->number ^ a->number;
		a->number = a->number ^ a->next->number;
	}
}

void	command_p(t_stack **a, t_stack **b)
{
	t_stack *c;

	if (*b != NULL)
	{
		c = *b;
		*b = (*b)->next;
		c->next = *a;
		*a = c;
	}
}

void	command_r(t_stack **a)
{
	t_stack *ptr;

	ptr = *a;
	while (ptr->next != NULL)
		ptr = ptr->next;
	ptr->next = *a;
	*a = (*a)->next;
	ptr->next->next = NULL;
}

void	command_rr(t_stack **a)
{
	t_stack *ptr;
	t_stack *p;

	ptr = *a;
	while (ptr->next->next != NULL)
		ptr = ptr->next;
	p = ptr->next;
	ptr->next = NULL;
	p->next = *a;
	*a = p;
}