/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 15:40:20 by amelikia          #+#    #+#             */
/*   Updated: 2018/11/22 15:40:31 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_stack_a(t_list *stack_a, int last_sorted)
{
	while (stack_a)
	{
		if (stack_a->pos == last_sorted + 1)
			return (1);
		stack_a = stack_a->next;
	}
	return (0);
}

int		check_stack_b(t_list *stack_b, int last_sorted)
{
	while (stack_b)
	{
		if (stack_b->pos == last_sorted + 1)
		{
			last_sorted++;
			return (last_sorted);
		}
		stack_b = stack_b->next;
	}
	return (last_sorted);
}

void	find_last_sorted(t_list **stack_a, t_list **stack_b,
	t_comm **commands, int *last_sorted)
{
	first_two(stack_a, stack_b, commands);
	*last_sorted = push_while(stack_a, stack_b, commands);
}

int		solver(t_list **stack_a, t_list **stack_b, t_comm **commands, int end)
{
	int	last_sorted;
	int i;

	i = 0;
	if (check_answer(*stack_a, *stack_b) == 1)
		return (1);
	find_last_sorted(stack_a, stack_b, commands, &last_sorted);
	if (check_answer(*stack_a, *stack_b) == 1)
		return (1);
	while (check_stack_a(*stack_a, last_sorted) != 1)
	{
		last_sorted = check_stack_b(*stack_b, last_sorted);
		if (last_sorted == end)
		{
			last_sorted--;
			break ;
		}
		i++;
	}
	push_b_while(stack_a, stack_b, commands, last_sorted);
	last_sorted = push_back(stack_a, stack_b, commands, last_sorted - i);
	rotate_back(stack_a, commands, last_sorted);
	if (check_answer(*stack_a, *stack_b) == 1)
		return (1);
	return (0);
}
