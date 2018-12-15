/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_solution.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 19:48:20 by amelikia          #+#    #+#             */
/*   Updated: 2018/12/14 19:48:20 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bring_first_pos_forward(t_list **stack_a)
{
	if (count_rotate(*stack_a, 1) < count_reverse_rotate(*stack_a, 1))
		while ((*stack_a)->pos != 1)
		{
			ft_printf("ra\n");
			rotate(stack_a);
		}
	else
		while ((*stack_a)->pos != 1)
		{
			ft_printf("rra\n");
			reverse_rotate(stack_a);
		}
}

int		find_solution(t_list **stack_a)
{
	t_list	*stack_b;
	t_list	*temp;
	int		beginning_chain;

	stack_b = NULL;
	*stack_a = list_assign_pos(*stack_a);
	temp = ft_list_dup(*stack_a);
	beginning_chain = find_the_biggest_chain(temp);
	define_biggest_chain(stack_a, beginning_chain);
	push_b_but_chain(stack_a, &stack_b);
	while (stack_b != NULL)
		find_and_apply_minimal_oper(stack_a, &stack_b);
	bring_first_pos_forward(stack_a);
	return (0);
}
