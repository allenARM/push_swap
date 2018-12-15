/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clean.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 19:50:23 by amelikia          #+#    #+#             */
/*   Updated: 2018/12/14 19:50:23 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_list_clean(t_list **list)
{
	t_list *node;

	if (*list == NULL || list == NULL)
		return ;
	node = *list;
	if (node && node->next)
		ft_list_clean(&node->next);
	ft_memdel((void**)list);
}
