/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_minimal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 17:50:35 by amelikia          #+#    #+#             */
/*   Updated: 2018/12/14 18:21:15 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_minimal(t_minimal *min)
{
	min->ra = 0;
	min->rb = 0;
	min->rra = 0;
	min->rrb = 0;
	min->rr = 0;
	min->rrr = 0;
	min->current_total = 2147483647;
}
