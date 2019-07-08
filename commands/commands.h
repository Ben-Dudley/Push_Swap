//
// Created by Ben Dudley on 2019-07-08.
//

#ifndef PUSH_SWAP_COMMANDS_H
#define PUSH_SWAP_COMMANDS_H

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

#endif //PUSH_SWAP_COMMANDS_H
