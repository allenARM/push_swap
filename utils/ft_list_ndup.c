/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_ndup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 15:42:20 by amelikia          #+#    #+#             */
/*   Updated: 2018/11/22 15:43:14 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_list		*ft_list_ndup(t_list *list, int size)
{
	t_list	*new;
	t_list	*tmp;

	new = NULL;
	tmp = list;
	while (tmp && size > 0)
	{
		new = ft_list_add_back(new, tmp->data, tmp->pos);
		tmp = tmp->next;
		--size;
	}
	return (tmp);
}
