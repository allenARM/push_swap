/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_back.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 19:50:38 by amelikia          #+#    #+#             */
/*   Updated: 2018/12/14 19:50:38 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void			ft_list_remove_back(t_list **list)
{
	t_list		*tmp;
	t_list		*node;

	if (*list == NULL)
		return ;
	if (ft_list_size(*list) == 1)
	{
		free(*list);
		*list = NULL;
		return ;
	}
	node = *list;
	while (node->next->next)
		node = node->next;
	tmp = node->next;
	node->next = NULL;
	free(tmp);
}
