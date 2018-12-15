/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_with_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 17:33:00 by amelikia          #+#    #+#             */
/*   Updated: 2018/12/14 18:55:34 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	deal_with_b(t_list **tmp, t_list *stack_b,\
	t_minimal *min, t_list *stack_a)
{
	int		pos_a;
	t_comm	*commands;

	commands = NULL;
	set_minimal(min);
	find_minimal(stack_b, min, (*tmp)->pos, 'b');
	pos_a = right_pos_in_a(stack_a, (*tmp)->pos);
	find_minimal(stack_a, min, pos_a, 'a');
	find_total(min, &commands);
	if (min->current_total < min->best_total)
	{
		min->best_pos = (*tmp)->pos;
		min->best_total = min->current_total;
		ft_comm_clean(&min->commands);
		min->commands = commands;
	}
	else
		ft_comm_clean(&commands);
	rotate(tmp);
}
