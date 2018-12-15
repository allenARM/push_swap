/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_add_front.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 19:50:13 by amelikia          #+#    #+#             */
/*   Updated: 2018/12/14 19:50:14 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_list	*ft_list_add_front(t_list *list, int data, int pos, int if_chain)
{
	t_list		*node;

	if (list == NULL)
	{
		list = (t_list *)malloc(sizeof(t_list));
		list->data = data;
		list->next = NULL;
		list->pos = pos;
		list->if_chain = if_chain;
		return (list);
	}
	node = (t_list *)malloc(sizeof(t_list));
	node->next = list;
	node->data = data;
	node->pos = pos;
	node->if_chain = if_chain;
	return (node);
}
