/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_add_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 19:50:09 by amelikia          #+#    #+#             */
/*   Updated: 2018/12/14 19:50:09 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_list	*ft_list_add_back(t_list *list, int data, int pos, int if_chain)
{
	t_list		*begining;
	t_list		*node;

	if (list == NULL)
	{
		list = (t_list *)malloc(sizeof(t_list));
		list->data = data;
		list->pos = pos;
		list->if_chain = if_chain;
		list->next = NULL;
		return (list);
	}
	node = (t_list *)malloc(sizeof(t_list));
	begining = list;
	node->next = NULL;
	node->data = data;
	node->pos = pos;
	node->if_chain = if_chain;
	while (list->next)
		list = list->next;
	list->next = node;
	return (begining);
}
