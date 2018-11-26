/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 15:39:09 by amelikia          #+#    #+#             */
/*   Updated: 2018/11/22 15:40:31 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	first_two(t_list **stack_a, t_list **stack_b, t_comm **commands)
{
	if (ft_list_size(*stack_a) >= 2 && ft_list_size(*stack_b) >= 2)
	{
		if (((*stack_a)->pos - (*stack_a)->next->pos == 1)
		&& ((*stack_b)->pos - (*stack_b)->next->pos == -1))
		{
			swap(stack_a);
			swap(stack_b);
			*commands = ft_comm_add_back((*commands), "ss");
		}
	}
	else
	{
		if (ft_list_size(*stack_a) >= 2)
			if ((*stack_a)->pos - (*stack_a)->next->pos == 1)
			{
				swap(stack_a);
				*commands = ft_comm_add_back((*commands), "sa");
			}
		if (ft_list_size(*stack_b) >= 2)
			if ((*stack_b)->pos - (*stack_b)->next->pos == -1)
			{
				swap(stack_b);
				*commands = ft_comm_add_back((*commands), "sb");
			}
	}
}
