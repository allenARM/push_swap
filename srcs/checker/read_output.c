/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_output.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 15:37:52 by amelikia          #+#    #+#             */
/*   Updated: 2018/11/22 15:37:52 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	run_input_1(char **input, t_list **stack_a, t_list **stack_b)
{
	if (!ft_strcmp(*input, "sa"))
		swap(stack_a);
	else if (!ft_strcmp(*input, "sb"))
		swap(stack_b);
	else if (!ft_strcmp(*input, "ss"))
	{
		swap(stack_a);
		swap(stack_b);
	}
	else if (!ft_strcmp(*input, "pa"))
		push(stack_b, stack_a);
	else if (!ft_strcmp(*input, "pb"))
		push(stack_a, stack_b);
	else if (!ft_strcmp(*input, "ra"))
		rotate(stack_a);
	else if (!ft_strcmp(*input, "rb"))
		rotate(stack_b);
	else if (!ft_strcmp(*input, "rr"))
	{
		rotate(stack_a);
		rotate(stack_b);
	}
}

void	run_input_2(char **input, t_list **stack_a, t_list **stack_b)
{
	if (!ft_strcmp(*input, "rra"))
		reverse_rotate(stack_a);
	else if (!ft_strcmp(*input, "rrb"))
		reverse_rotate(stack_b);
	else if (!ft_strcmp(*input, "rrr"))
	{
		reverse_rotate(stack_a);
		reverse_rotate(stack_b);
	}
}

int		check_input(char *input)
{
	if ((!ft_strcmp(input, "rr")) || (!ft_strcmp(input, "rb")) ||
		(!ft_strcmp(input, "ra")) || (!ft_strcmp(input, "pa")) ||
		(!ft_strcmp(input, "sa")) || (!ft_strcmp(input, "sb")) ||
		(!ft_strcmp(input, "pb")) || (!ft_strcmp(input, "ss")) ||
		(!ft_strcmp(input, "rrr")) || (!ft_strcmp(input, "rrb")) ||
		(!ft_strcmp(input, "rra")))
		return (1);
	return (-1);
}

void	flag_v_check(t_list **stack_a, t_list **stack_b,
	int flag_v, int flag_c)
{
	if (flag_v == 1)
		print_status(*stack_a, *stack_b, flag_c);
}

int		read_output(t_list **stack_a, int flag_v, int flag_c)
{
	t_list		*stack_b;
	char		*input;

	stack_b = NULL;
	if (check_for_duplicates(*stack_a) == -1)
		return (-1);
	while (get_next_line(0, &input) > 0)
	{
		if (check_input(input) == 1)
			run_input_1(&input, stack_a, &stack_b);
		if (check_input(input) == 1)
			run_input_2(&input, stack_a, &stack_b);
		else if (!ft_strcmp(input, "exit"))
			break ;
		else
		{
			ft_strdel(&input);
			return (-1);
		}
		flag_v_check(stack_a, &stack_b, flag_v, flag_c);
		ft_strdel(&input);
	}
	check_result(stack_a, stack_b);
	ft_strdel(&input);
	return (0);
}
