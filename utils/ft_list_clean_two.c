/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clean_two.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 19:50:18 by amelikia          #+#    #+#             */
/*   Updated: 2018/12/14 19:50:18 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_list_clean_two(t_list **a, t_list **b)
{
	if (*a != NULL)
		ft_list_clean(a);
	if (*b != NULL)
		ft_list_clean(b);
}
