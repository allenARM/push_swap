/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_comm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 17:53:05 by amelikia          #+#    #+#             */
/*   Updated: 2018/12/14 18:38:54 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_comm_ra_rb(t_minimal *min, t_comm **commands)
{
	int	i;

	if (min->rr == min->ra)
	{
		i = 0;
		while (++i <= min->rr)
			*commands = ft_comm_add_back(*commands, "rr");
		i = 0;
		while (++i <= min->rb - min->rr)
			*commands = ft_comm_add_back(*commands, "rb");
	}
	else if (min->rr == min->rb)
	{
		i = 0;
		while (++i <= min->rr)
			*commands = ft_comm_add_back(*commands, "rr");
		i = 0;
		while (++i <= min->ra - min->rr)
			*commands = ft_comm_add_back(*commands, "ra");
	}
}

void	assign_comm_rra_rb(t_minimal *min, t_comm **commands)
{
	int	i;

	i = 0;
	while (++i <= min->rra)
		*commands = ft_comm_add_back(*commands, "rra");
	i = 0;
	while (++i <= min->rb)
		*commands = ft_comm_add_back(*commands, "rb");
}

void	assign_comm_ra_rrb(t_minimal *min, t_comm **commands)
{
	int	i;

	i = 0;
	while (++i <= min->ra)
		*commands = ft_comm_add_back(*commands, "ra");
	i = 0;
	while (++i <= min->rrb)
		*commands = ft_comm_add_back(*commands, "rrb");
}

void	assign_comm_rra_rrb(t_minimal *min, t_comm **commands)
{
	int	i;

	if (min->rrr == min->rra)
	{
		i = 0;
		while (++i <= min->rrr)
			*commands = ft_comm_add_back(*commands, "rrr");
		i = 0;
		while (++i <= min->rrb - min->rrr)
			*commands = ft_comm_add_back(*commands, "rrb");
	}
	else if (min->rrr == min->rrb)
	{
		i = 0;
		while (++i <= min->rrr)
			*commands = ft_comm_add_back(*commands, "rrr");
		i = 0;
		while (++i <= min->rra - min->rrr)
			*commands = ft_comm_add_back(*commands, "rra");
	}
}
