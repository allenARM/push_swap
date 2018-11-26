/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_push_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 15:38:49 by amelikia          #+#    #+#             */
/*   Updated: 2018/11/22 15:38:50 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_push_swap(int flag_optimized, t_list **stack)
{
	*stack = list_assign_pos(*stack);
	if (*stack == NULL)
	{
		write(2, "Error\n", 6);
		return ;
	}
	if (check_for_duplicates(*stack) == -1)
	{
		write(2, "Error\n", 6);
		return ;
	}
	if (find_optimal_solution(*stack, flag_optimized) == 0)
		find_solution(stack);
	ft_list_clean(stack);
}
