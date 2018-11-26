/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_while.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 15:39:52 by amelikia          #+#    #+#             */
/*   Updated: 2018/11/22 15:40:31 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	while_push_while(t_list **stack_a, t_comm **commands)
{
	int where_is_one;
	int list_size;

	list_size = ft_list_size(*stack_a);
	where_is_one = find_in_list(*stack_a, 1);
	while ((*stack_a)->pos != 1)
	{
		if (where_is_one > list_size / 2)
		{
			reverse_rotate(stack_a);
			*commands = ft_comm_add_back((*commands), "rra");
		}
		else
		{
			rotate(stack_a);
			*commands = ft_comm_add_back((*commands), "ra");
		}
	}
}

int		push_while(t_list **stack_a, t_list **stack_b, t_comm **commands)
{
	int ret;

	while_push_while(stack_a, commands);
	if (ft_list_size(*stack_a) > 2)
	{
		while ((*stack_a)->pos - (*stack_a)->next->pos == -1)
		{
			if (check_answer(*stack_a, *stack_b) == 1)
			{
				reverse_rotate(stack_a);
				ret = (*stack_a)->pos;
				rotate(stack_a);
				return (ret);
			}
			rotate(stack_a);
			*commands = ft_comm_add_back((*commands), "ra");
			first_two(stack_a, stack_b, commands);
		}
	}
	ret = (*stack_a)->pos;
	rotate(stack_a);
	*commands = ft_comm_add_back((*commands), "ra");
	return (ret);
}
