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

void	command_r_r(t_stack **a, t_stack **b, t_list **commands, char *str)
{
	command_r(a, commands, str);
	command_r(b, commands, str);
}

void	command_rrr(t_stack **a, t_stack **b, t_list **commands, char *str)
{
	command_rr(a, commands, str);
	command_rr(b, commands, str);
}

void	command_ss(t_stack **a, t_stack **b, t_list **commands, char *str)
{
	command_s(*a, commands, str);
	command_s(*b, commands, str);
}
