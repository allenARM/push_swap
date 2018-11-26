/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 15:38:12 by amelikia          #+#    #+#             */
/*   Updated: 2018/11/22 15:38:12 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void		swap(t_list **list)
{
	t_list		*elem1;
	t_list		*elem2;
	int			tmp;

	if (ft_list_size(*list) < 2)
		return ;
	elem1 = *list;
	elem2 = elem1->next;
	tmp = elem1->data;
	elem1->data = elem2->data;
	elem2->data = tmp;
	tmp = elem1->pos;
	elem1->pos = elem2->pos;
	elem2->pos = tmp;
}
