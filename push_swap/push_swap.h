//
// Created by Ben Dudley on 2019-07-08.
//

#ifndef PUSH_SWAP_PUSH_SWAP_H
#define PUSH_SWAP_PUSH_SWAP_H

#include "stack.h"
#include <limits.h>
#include <unistd.h>

int		get_last_element(t_stack *a);
void	sort_a(t_stack **a, t_stack **b);
void	sort_b(t_stack **a, t_stack **b);

#endif //PUSH_SWAP_PUSH_SWAP_H
