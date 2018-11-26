/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_rec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 15:40:26 by amelikia          #+#    #+#             */
/*   Updated: 2018/11/22 15:40:31 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			swap_rec_sa(t_list *stack_a, t_list *stack_b, int set_depth, \
		t_comm **command_list)
{
	if (check_last_comm(*command_list, "sa") == 1 || \
			check_last_comm(*command_list, "sb") == 1 || \
			ft_list_size(stack_a) == 1 || stack_a == NULL)
		return (-1);
	*command_list = ft_comm_add_back(*command_list, "sa");
	if (search(stack_a, stack_b, set_depth - 1, command_list) != 1)
	{
		ft_comm_remove_back(command_list);
		return (-1);
	}
	return (1);
}

int			swap_rec_sb(t_list *stack_a, t_list *stack_b, int set_depth, \
		t_comm **command_list)
{
	if (check_last_comm(*command_list, "sa") == 1 || \
			check_last_comm(*command_list, "sb") == 1 || \
			ft_list_size(stack_b) == 1 || stack_b == NULL)
		return (-1);
	*command_list = ft_comm_add_back(*command_list, "sb");
	if (search(stack_a, stack_b, set_depth - 1, command_list) != 1)
	{
		ft_comm_remove_back(command_list);
		return (-1);
	}
	return (1);
}

int			swap_rec_ss(t_list *stack_a, t_list *stack_b, int set_depth, \
		t_comm **command_list)
{
	*command_list = ft_comm_add_back(*command_list, "ss");
	if (search(stack_a, stack_b, set_depth - 1, command_list) != 1)
	{
		ft_comm_remove_back(command_list);
		return (-1);
	}
	return (1);
}

int			swap_rec(t_list *stack_a, t_list *stack_b, int set_depth, \
		t_comm **command_list)
{
	t_list	*temp_a;
	t_list	*temp_b;

	temp_a = ft_list_dup(stack_a);
	temp_b = ft_list_dup(stack_b);
	swap(&temp_a);
	swap(&temp_b);
	if (swap_rec_sa(temp_a, stack_b, set_depth, command_list) == 1)
	{
		ft_list_clean_two(&temp_a, &temp_b);
		return (1);
	}
	if (swap_rec_sb(stack_a, temp_b, set_depth, command_list) == 1)
	{
		ft_list_clean_two(&temp_a, &temp_b);
		return (1);
	}
	if (swap_rec_ss(temp_a, temp_b, set_depth, command_list) == 1)
	{
		ft_list_clean_two(&temp_a, &temp_b);
		return (1);
	}
	ft_list_clean_two(&temp_a, &temp_b);
	return (-1);
}
