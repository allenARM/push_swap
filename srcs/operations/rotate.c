/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 19:46:56 by amelikia          #+#    #+#             */
/*   Updated: 2018/12/14 19:46:56 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void		rotate(t_list **list)
{
	t_list	*node;

	if (ft_list_size(*list) < 2)
		return ;
	node = *list;
	*list = ft_list_add_back(*list, node->data, node->pos, node->if_chain);
	ft_list_remove_front(list);
}
