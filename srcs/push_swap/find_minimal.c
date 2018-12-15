/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_minimal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 17:51:14 by amelikia          #+#    #+#             */
/*   Updated: 2018/12/14 17:53:18 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_minimal(t_list *stack, t_minimal *min, int pos, int id)
{
	if (id == 'a')
		count_rotate_rev_rotate(stack, pos, &min->ra, &min->rra);
	else
		count_rotate_rev_rotate(stack, pos, &min->rb, &min->rrb);
}
