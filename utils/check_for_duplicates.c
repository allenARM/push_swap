/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_for_duplicates.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 15:40:46 by amelikia          #+#    #+#             */
/*   Updated: 2018/11/22 15:43:14 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int			check_for_duplicates(t_list *stack)
{
	t_list	*tmp;
	int		count;

	while (stack)
	{
		count = 0;
		tmp = stack;
		while (tmp)
		{
			if (stack->data == tmp->data)
			{
				count++;
				if (count > 1)
					return (-1);
			}
			tmp = tmp->next;
		}
		stack = stack->next;
	}
	return (0);
}
