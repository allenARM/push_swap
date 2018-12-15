/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_the_biggest_chain.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 16:11:25 by amelikia          #+#    #+#             */
/*   Updated: 2018/12/14 17:53:27 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		while_loop_of_chain(t_list **stack_a, int length,\
	int max_length, int tracker)
{
	int begin_pos;

	while ((*stack_a)->pos)
	{
		if (length != 0 && (*stack_a)->pos < (*stack_a)->next->pos)
			++length;
		if (length == 0 && (*stack_a)->pos < (*stack_a)->next->pos)
		{
			++length;
			tracker = (*stack_a)->pos;
		}
		if ((*stack_a)->pos > (*stack_a)->next->pos)
		{
			if (length > max_length)
			{
				max_length = length;
				begin_pos = tracker;
			}
			length = 0;
		}
		rotate(stack_a);
		if ((*stack_a)->pos == 1)
			break ;
	}
	return (begin_pos);
}

int		find_the_biggest_chain(t_list *stack_a)
{
	int		max_length;
	int		length;
	int		begin_pos;
	int		tracker;
	int		last;

	last = find_the_last_number(stack_a);
	rotate_until(&stack_a, 1);
	tracker = 0;
	length = 0;
	max_length = 0;
	begin_pos = 1;
	if (ft_list_size(stack_a) == 1)
		return (1);
	begin_pos = while_loop_of_chain(&stack_a, length, max_length, tracker);
	ft_list_clean(&stack_a);
	return (begin_pos);
}
