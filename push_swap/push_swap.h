/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdudley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 22:20:36 by bdudley           #+#    #+#             */
/*   Updated: 2019/07/17 22:32:58 by bdudley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_PUSH_SWAP_H
# define PUSH_SWAP_PUSH_SWAP_H

# include "stack.h"

void	sort(t_stack **a, t_stack **b, int count);
void	small_sort(t_stack **a, t_stack **b, int count_a, int count_b);
int		get_element(t_stack *a, int count);

#endif
