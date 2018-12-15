/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_the_last_number.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 16:16:33 by amelikia          #+#    #+#             */
/*   Updated: 2018/12/14 17:53:30 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		find_the_last_number(t_list *stack_a)
{
	t_list	*tmp;
	int		i;

	i = 0;
	while (stack_a)
	{
		tmp = stack_a;
		while (tmp)
		{
			if (i < tmp->pos)
				i = tmp->pos;
			tmp = tmp->next;
		}
		stack_a = stack_a->next;
	}
	return (i);
}
