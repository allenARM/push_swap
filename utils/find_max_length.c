/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_max_length.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 15:41:05 by amelikia          #+#    #+#             */
/*   Updated: 2018/11/22 15:43:14 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int			find_max_length(t_list *list)
{
	int			max;
	int			tmp;
	int			count;

	max = 0;
	while (list)
	{
		tmp = list->data;
		if (tmp == -2147483648)
			return (11);
		count = 0;
		if (tmp < 0)
			count = 1;
		if (tmp < 0)
			tmp = -tmp;
		while (tmp > 9)
		{
			tmp = tmp / 10;
			++count;
		}
		if (++count > max)
			max = count;
		list = list->next;
	}
	return (max);
}
