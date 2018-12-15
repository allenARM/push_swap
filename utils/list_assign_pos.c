/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_assign_pos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 19:50:56 by amelikia          #+#    #+#             */
/*   Updated: 2018/12/14 19:50:57 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

t_list		*list_assign_pos(t_list *stack)
{
	t_list		*list1;
	t_list		*list2;
	int			count;

	list1 = stack;
	while (list1)
	{
		list2 = stack;
		count = 0;
		while (list2)
		{
			if (list1->data > list2->data)
				++count;
			list2 = list2->next;
		}
		list1->pos = count + 1;
		list1 = list1->next;
	}
	return (stack);
}
