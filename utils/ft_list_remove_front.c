/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_front.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 19:50:43 by amelikia          #+#    #+#             */
/*   Updated: 2018/12/14 19:50:43 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void			ft_list_remove_front(t_list **list)
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
	tmp = *list;
	node = tmp->next;
	if (tmp)
	{
		tmp->next = NULL;
		free(tmp);
	}
	*list = node;
}
