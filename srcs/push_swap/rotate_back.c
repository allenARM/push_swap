/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_back.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 15:40:03 by amelikia          #+#    #+#             */
/*   Updated: 2018/11/22 15:40:31 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_back(t_list **stack_a,
	t_comm **commands, int num)
{
	int list_a_size;
	int	where_is_one;

	where_is_one = find_in_list((*stack_a), 1);
	list_a_size = ft_list_size(*stack_a);
	if (where_is_one < list_a_size / 2)
	{
		while (num > 0)
		{
			rotate(stack_a);
			*commands = ft_comm_add_back((*commands), "ra");
			num--;
		}
	}
	else
	{
		while (num < list_a_size)
		{
			reverse_rotate(stack_a);
			*commands = ft_comm_add_back((*commands), "rra");
			num++;
		}
	}
}
