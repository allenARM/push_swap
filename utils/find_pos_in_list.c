/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pos_in_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 19:49:44 by amelikia          #+#    #+#             */
/*   Updated: 2018/12/14 19:49:44 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int		find_in_list(t_list *root, int num)
{
	int		i;
	t_list	*entity;

	i = 1;
	if (!root)
		return (0);
	if (root)
	{
		entity = root;
		while (entity)
		{
			if (entity->pos == num)
				break ;
			(entity = entity->next) && i++;
		}
	}
	return (i);
}
