/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_solution.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 15:39:00 by amelikia          #+#    #+#             */
/*   Updated: 2018/11/22 15:40:31 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		find_the_last_number(t_list *stack_a)
{
	t_list	*tmp;
	int		i;

	i = 0;
	while (stack_a)
	{
		tmp = stack_a;
		while (tmp)
		{
			if (i < tmp->pos)
				i = tmp->pos;
			tmp = tmp->next;
		}
		stack_a = stack_a->next;
	}
	return (i);
}

t_comm	*check_for_two_stack_rotations(t_comm *commands)
{
	t_comm	*new;
	t_comm	*tmp;

	new = NULL;
	tmp = commands;
	while (commands)
	{
		if (!ft_strcmp(commands->command, "ra"))
			fix_double_rotations("ra", "rb", &commands, &new);
		else if (!ft_strcmp(commands->command, "rb"))
			fix_double_rotations("rb", "ra", &commands, &new);
		else if (!ft_strcmp(commands->command, "rra"))
			fix_double_rotations("rra", "rrb", &commands, &new);
		else if (!ft_strcmp(commands->command, "rrb"))
			fix_double_rotations("rrb", "rra", &commands, &new);
		else
			new = ft_comm_add_back(new, commands->command);
		if (commands)
			commands = commands->next;
	}
	ft_comm_clean(&tmp);
	return (new);
}

t_comm	*optimize(t_comm *commands)
{
	while (check_for_right_commnds(commands) == 0)
		commands = optimize_answer(commands);
	commands = check_for_two_stack_rotations(commands);
	return (commands);
}

int		find_solution(t_list **stack_a)
{
	t_list	*stack_b;
	t_comm	*tmp;
	t_comm	*commands;
	int		end;
	int		stop;

	stop = 0;
	commands = NULL;
	stack_b = NULL;
	*stack_a = list_assign_pos(*stack_a);
	end = find_the_last_number(*stack_a);
	while (1)
		if (solver(stack_a, &stack_b, &commands, end) == 1)
			break ;
	if (!commands)
		return (0);
	commands = optimize(commands);
	tmp = commands;
	while (commands)
	{
		ft_printf("%s\n", commands->command);
		commands = commands->next;
	}
	ft_comm_clean(&tmp);
	return (0);
}
