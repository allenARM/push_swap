/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_last_pos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 17:50:15 by amelikia          #+#    #+#             */
/*   Updated: 2018/12/14 17:53:17 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		find_last_pos(t_list *stack)
{
	if (stack == NULL)
		return (0);
	while (stack->next)
		stack = stack->next;
	return (stack->pos);
}
