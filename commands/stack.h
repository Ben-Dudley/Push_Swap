//
// Created by Ben Dudley on 2019-07-08.
//

#ifndef PUSH_SWAP_STACK_H
#define PUSH_SWAP_STACK_H

#include <stdlib.h>
#include <stdio.h>

typedef struct s_stack
{
	int number;
	struct s_stack *next;
} t_stack;

void	command_s(t_stack *a);
void	command_p(t_stack **a, t_stack **b);
void	command_r(t_stack **a);
void	push(t_stack **a, int number);
void	pop(t_stack **a);
int		exist(t_stack *a, int number);


#endif //PUSH_SWAP_STACK_H
