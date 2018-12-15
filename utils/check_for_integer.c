/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_for_integer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 19:49:24 by amelikia          #+#    #+#             */
/*   Updated: 2018/12/14 19:49:24 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int		check_for_integer(char *str)
{
	if (str[0] == '-')
		if (ft_strlen(str) > 11)
			return (-1);
	if (str[0] != '-')
		if (ft_strlen(str) > 10)
			return (-1);
	if (str[0] == '-' && ft_strlen(str) == 11)
		if (ft_strcmp(str, "-2147483648") > 0)
			return (-1);
	if (str[0] != '-' && ft_strlen(str) == 10)
		if (ft_strcmp(str, "2147483647") > 0)
			return (-1);
	return (0);
}
