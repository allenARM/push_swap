/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_rec.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 19:47:35 by amelikia          #+#    #+#             */
/*   Updated: 2018/12/14 19:47:35 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			reverse_rotate_rec_rra(t_list *stack_a, t_list *stack_b, \
		int set_depth, t_comm **command_list)
{
	if (check_last_comm(*command_list, "ra") == 1 || \
			check_last_comm(*command_list, "rrb") == 1 || \
			ft_list_size(stack_a) == 1 || stack_a == NULL)
		return (-1);
	*command_list = ft_comm_add_back(*command_list, "rra");
	if (search(stack_a, stack_b, set_depth - 1, command_list) != 1)
	{
		ft_comm_remove_back(command_list);
		return (-1);
	}
	return (1);
}

int			reverse_rotate_rec_rrb(t_list *stack_a, t_list *stack_b, \
		int set_depth, t_comm **command_list)
{
	if (check_last_comm(*command_list, "rb") == 1 || \
			check_last_comm(*command_list, "rra") == 1 || \
			ft_list_size(stack_b) == 1 || stack_b == NULL)
		return (-1);
	*command_list = ft_comm_add_back(*command_list, "rrb");
	if (search(stack_a, stack_b, set_depth - 1, command_list) != 1)
	{
		ft_comm_remove_back(command_list);
		return (-1);
	}
	return (1);
}

int			reverse_rotate_rec_rrr(t_list *stack_a, t_list *stack_b, \
		int set_depth, t_comm **command_list)
{
	*command_list = ft_comm_add_back(*command_list, "rrr");
	if (search(stack_a, stack_b, set_depth - 1, command_list) != 1)
	{
		ft_comm_remove_back(command_list);
		return (-1);
	}
	return (1);
}

int			reverse_rotate_rec(t_list *stack_a, t_list *stack_b, \
		int set_depth, t_comm **command_list)
{
	t_list	*temp_a;
	t_list	*temp_b;

	temp_a = ft_list_dup(stack_a);
	temp_b = ft_list_dup(stack_b);
	reverse_rotate(&temp_a);
	reverse_rotate(&temp_b);
	if (reverse_rotate_rec_rra(temp_a, stack_b, set_depth, command_list) == 1)
	{
		ft_list_clean_two(&temp_a, &temp_b);
		return (1);
	}
	if (reverse_rotate_rec_rrb(stack_a, temp_b, set_depth, command_list) == 1)
	{
		ft_list_clean_two(&temp_a, &temp_b);
		return (1);
	}
	if (reverse_rotate_rec_rrr(temp_a, temp_b, set_depth, command_list) == 1)
	{
		ft_list_clean_two(&temp_a, &temp_b);
		return (1);
	}
	ft_list_clean_two(&temp_a, &temp_b);
	return (-1);
}
