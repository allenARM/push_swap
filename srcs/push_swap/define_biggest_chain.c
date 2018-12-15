/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_biggest_chain.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 16:17:45 by amelikia          #+#    #+#             */
/*   Updated: 2018/12/14 17:53:12 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	define_biggest_chain(t_list **stack_a, int beginning_chain)
{
	int		head;

	head = (*stack_a)->pos;
	while ((*stack_a)->pos != beginning_chain)
	{
		(*stack_a)->if_chain = 0;
		rotate(stack_a);
	}
	while ((*stack_a)->pos < (*stack_a)->next->pos)
	{
		(*stack_a)->if_chain = 1;
		rotate(stack_a);
	}
	(*stack_a)->if_chain = 1;
	rotate(stack_a);
	while ((*stack_a)->pos != beginning_chain)
	{
		(*stack_a)->if_chain = 0;
		rotate(stack_a);
	}
	rotate_until(stack_a, head);
}
