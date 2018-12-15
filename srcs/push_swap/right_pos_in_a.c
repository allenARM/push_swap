/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   right_pos_in_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 17:52:00 by amelikia          #+#    #+#             */
/*   Updated: 2018/12/14 17:53:36 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		right_pos_in_a(t_list *stack_a, int pos)
{
	t_list	*tmp;
	int		pos_a;

	pos_a = find_pos(stack_a, -1);
	if (pos < pos_a || pos > find_pos(stack_a, 1))
		return (pos_a);
	tmp = ft_list_dup(stack_a);
	rotate_until(&tmp, pos_a);
	while (tmp->pos < pos)
		rotate(&tmp);
	pos_a = tmp->pos;
	ft_list_clean(&tmp);
	return (pos_a);
}
