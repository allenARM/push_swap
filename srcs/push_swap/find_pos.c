/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pos.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 17:51:29 by amelikia          #+#    #+#             */
/*   Updated: 2018/12/14 17:53:19 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		find_pos(t_list *stack_a, int min_max)
{
	t_list	*tmp;
	int		min;
	int		max;

	max = 0;
	min = 2147483647;
	tmp = stack_a;
	while (tmp)
	{
		if (max < tmp->pos && min_max == 1)
			max = tmp->pos;
		if (min > tmp->pos && min_max == -1)
			min = tmp->pos;
		tmp = tmp->next;
	}
	if (min_max == -1)
		return (min);
	return (max);
}
