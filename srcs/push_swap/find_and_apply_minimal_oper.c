/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_and_apply_minimal_oper.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 17:50:20 by amelikia          #+#    #+#             */
/*   Updated: 2018/12/14 18:29:32 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		return_minimal(int n1, int n2)
{
	return (n1 > n2 ? n2 : n1);
}

void	find_and_apply_minimal_oper(t_list **stack_a,\
	t_list **stack_b)
{
	int			begin_b;
	t_list		*tmp;
	t_minimal	min;

	begin_b = find_last_pos(*stack_b);
	min.best_total = 2147483647;
	min.best_pos = 0;
	tmp = ft_list_dup(*stack_b);
	min.commands = NULL;
	while (tmp->pos != begin_b && min.best_total > 2)
		deal_with_b(&tmp, *stack_b, &min, *stack_a);
	deal_with_b(&tmp, *stack_b, &min, *stack_a);
	apply_commands(stack_a, stack_b, min.commands);
	ft_list_clean(&tmp);
}
