/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_total.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 17:34:57 by amelikia          #+#    #+#             */
/*   Updated: 2018/12/14 18:40:12 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_diff(t_minimal *min, int *total_ra_rb, int *total_rra_rrb)
{
	if (min->ra > min->rb)
	{
		min->rr = min->rb;
		*total_ra_rb = min->ra;
	}
	else
	{
		min->rr = min->ra;
		*total_ra_rb = min->rb;
	}
	if (min->rra > min->rrb)
	{
		min->rrr = min->rrb;
		*total_rra_rrb = min->rra;
	}
	else
	{
		min->rrr = min->rra;
		*total_rra_rrb = min->rrb;
	}
}

void	find_total(t_minimal *min, t_comm **commands)
{
	int		total_ra_rb;
	int		total_rra_rb;
	int		total_ra_rrb;
	int		total_rra_rrb;

	total_rra_rb = min->rra + min->rb;
	total_ra_rrb = min->ra + min->rrb;
	find_diff(min, &total_ra_rb, &total_rra_rrb);
	min->current_total = return_minimal(\
	return_minimal(return_minimal(return_minimal(\
	min->current_total, total_ra_rrb), total_rra_rb), \
	total_rra_rrb), total_ra_rb);
	if (min->current_total == total_ra_rb)
		assign_comm_ra_rb(min, commands);
	else if (min->current_total == total_rra_rb)
		assign_comm_rra_rb(min, commands);
	else if (min->current_total == total_ra_rrb)
		assign_comm_ra_rrb(min, commands);
	else if (min->current_total == total_rra_rrb)
		assign_comm_rra_rrb(min, commands);
}
