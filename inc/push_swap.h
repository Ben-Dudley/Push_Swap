/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdudley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 22:21:50 by bdudley           #+#    #+#             */
/*   Updated: 2019/08/04 19:56:57 by bdudley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <stdio.h>
# include <unistd.h>
# include "libft.h"

typedef struct		s_stack
{
	int				number;
	struct s_stack	*next;
}					t_stack;

typedef struct		s_helper
{
	int				*count;
	t_list			*commands;
	int				max_count;
	int				sorted_count;
	int				count_a;
	int				i;
}					t_helper;

void				command_s(t_stack *a, t_list **commands, char *str);
void				command_p(t_stack **a, t_stack **b,
							t_list **commands, char *str);
void				command_r(t_stack **a, t_list **commands, char *str);
void				command_rr(t_stack **a,
							t_list **commands, char *str);
void				command_r_r(t_stack **a, t_stack **b,
							t_list **commands, char *str);
void				command_rrr(t_stack **a, t_stack **b,
							t_list **commands, char *str);
void				command_ss(t_stack **a, t_stack **b,
							t_list **commands, char *str);
void				delete_content(t_list **alst);

void				push(t_stack **a, int number);
void				pop(t_stack **a);
int					exist(t_stack *a, int number);
void				delete(t_stack **a);

int					is_sorted(t_stack *a, int count);
int					put_number(t_stack **a, char *str);
void				put_stack(int argc, char *argv[], t_stack **a, t_stack **b);
void				error(t_stack **a, t_stack **b, t_helper **help);
void				clear(t_stack **a, t_stack **b, t_helper **help);
void				rev_b(t_stack **a, t_stack **b,
						t_helper **help, int count_b);

void				sort(t_stack **a, t_stack **b, t_helper **help);
void				print_command(t_list *commands);
int					get_pivot(t_stack *a, int count);
void				small_sort(t_stack **a, t_stack **b, t_helper **help);
void				first_small_sort(t_stack **a, t_helper **help);

void				find_merge(int flag_1, t_list **commands,
					t_list **p, t_list **prev);
int					get_flag(const char *content);

#endif
