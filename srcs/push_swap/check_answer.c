/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_answer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 19:48:01 by amelikia          #+#    #+#             */
/*   Updated: 2018/12/14 19:48:02 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_answer(t_list *stack_a, t_list *stack_b)
{
	t_list		*tmp;

	tmp = stack_a;
	if (stack_b)
		return (-1);
	while (tmp->next)
	{
		if (tmp->data > tmp->next->data)
			return (-1);
		tmp = tmp->next;
	}
	return (1);
}
