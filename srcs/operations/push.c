/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 15:37:58 by amelikia          #+#    #+#             */
/*   Updated: 2018/11/22 15:37:58 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void		push(t_list **src, t_list **dst)
{
	t_list		*tmp;

	if (ft_list_size(*src) < 1)
		return ;
	tmp = *src;
	*dst = ft_list_add_front(*dst, tmp->data, tmp->pos);
	ft_list_remove_front(src);
}
