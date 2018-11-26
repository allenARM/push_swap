/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_dup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 15:42:09 by amelikia          #+#    #+#             */
/*   Updated: 2018/11/22 15:43:14 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_list		*ft_list_dup(t_list *list)
{
	t_list	*new;
	t_list	*tmp;

	new = NULL;
	tmp = list;
	if (list == NULL)
		return (NULL);
	while (tmp)
	{
		new = ft_list_add_back(new, tmp->data, tmp->pos);
		tmp = tmp->next;
	}
	return (new);
}
