/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combine_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdudley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 15:37:15 by bdudley           #+#    #+#             */
/*   Updated: 2019/07/26 15:47:25 by bdudley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	command_r_r(t_stack **a, t_stack **b)
{
	command_r(a);
	command_r(b);
}

void	command_rrr(t_stack **a, t_stack **b)
{
	command_rr(a);
	command_rr(b);
}

void	command_ss(t_stack **a, t_stack **b)
{
	command_s(*a);
	command_s(*b);
}
