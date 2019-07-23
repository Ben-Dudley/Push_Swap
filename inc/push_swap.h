/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdudley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 22:20:36 by bdudley           #+#    #+#             */
/*   Updated: 2019/07/23 21:06:29 by bdudley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_PUSH_SWAP_H
# define PUSH_SWAP_PUSH_SWAP_H

# include "stack.h"
# include "libft.h"

void	sort(t_stack **a, t_stack **b, t_helper **help);
void	small_sort(t_stack **a, t_stack **b, t_helper **help, int count[2]);
int		get_element(t_stack *a, int count);

#endif
