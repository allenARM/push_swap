/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_rec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 19:47:39 by amelikia          #+#    #+#             */
/*   Updated: 2018/12/14 19:47:39 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			rotate_rec_ra(t_list *stack_a, t_list *stack_b, int set_depth, \
		t_comm **command_list)
{
	if (check_last_comm(*command_list, "rra") == 1 || \
			check_last_comm(*command_list, "rb") == 1 || \
			ft_list_size(stack_a) == 1 || stack_a == NULL)
		return (-1);
	*command_list = ft_comm_add_back(*command_list, "ra");
	if (search(stack_a, stack_b, set_depth - 1, command_list) != 1)
	{
		ft_comm_remove_back(command_list);
		return (-1);
	}
	return (1);
}

int			rotate_rec_rb(t_list *stack_a, t_list *stack_b, int set_depth, \
		t_comm **command_list)
{
	if (check_last_comm(*command_list, "rrb") == 1 || \
			check_last_comm(*command_list, "ra") == 1 || \
			ft_list_size(stack_b) == 1 || stack_b == NULL)
		return (-1);
	*command_list = ft_comm_add_back(*command_list, "rb");
	if (search(stack_a, stack_b, set_depth - 1, command_list) != 1)
	{
		ft_comm_remove_back(command_list);
		return (-1);
	}
	return (1);
}

int			rotate_rec_rr(t_list *stack_a, t_list *stack_b, int set_depth, \
		t_comm **command_list)
{
	*command_list = ft_comm_add_back(*command_list, "rr");
	if (search(stack_a, stack_b, set_depth - 1, command_list) != 1)
	{
		ft_comm_remove_back(command_list);
		return (-1);
	}
	return (1);
}

int			rotate_rec(t_list *stack_a, t_list *stack_b, int set_depth, \
		t_comm **command_list)
{
	t_list		*temp_a;
	t_list		*temp_b;

	temp_a = ft_list_dup(stack_a);
	temp_b = ft_list_dup(stack_b);
	rotate(&temp_a);
	rotate(&temp_b);
	if (rotate_rec_ra(temp_a, stack_b, set_depth, command_list) == 1)
	{
		ft_list_clean_two(&temp_a, &temp_b);
		return (1);
	}
	if (rotate_rec_rb(stack_a, temp_b, set_depth, command_list) == 1)
	{
		ft_list_clean_two(&temp_a, &temp_b);
		return (1);
	}
	if (rotate_rec_rr(temp_a, temp_b, set_depth, command_list) == 1)
	{
		ft_list_clean_two(&temp_a, &temp_b);
		return (1);
	}
	ft_list_clean_two(&temp_a, &temp_b);
	return (-1);
}
