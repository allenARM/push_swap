/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_optimal_solution.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 15:38:55 by amelikia          #+#    #+#             */
/*   Updated: 2018/11/22 15:38:56 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_optimal_solution(t_list *stack_a, int flag_optimized)
{
	int			set_depth;
	t_comm		*command_list;
	t_comm		*tmp;
	t_list		*stack_b;

	if (flag_optimized == 0 && ft_list_size(stack_a) > 10)
		return (0);
	set_depth = 1;
	command_list = NULL;
	stack_b = NULL;
	while (search(stack_a, stack_b, set_depth, &command_list) == -1)
	{
		set_depth++;
		if (flag_optimized == 0 && set_depth == 8)
			return (0);
		command_list = NULL;
	}
	tmp = command_list;
	while (command_list)
	{
		ft_printf("%s\n", command_list->command);
		command_list = command_list->next;
	}
	ft_comm_clean(&tmp);
	return (1);
}
