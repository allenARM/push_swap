/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_last_comm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 15:38:45 by amelikia          #+#    #+#             */
/*   Updated: 2018/11/22 15:38:45 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_last_comm(t_comm *list, char *command)
{
	if (list == NULL)
		return (-1);
	while (list->next)
		list = list->next;
	if (!ft_strcmp(list->command, command))
		return (1);
	return (-1);
}
