/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 15:40:40 by amelikia          #+#    #+#             */
/*   Updated: 2018/11/22 15:43:14 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int		add_to_list(int i, char **argv, t_list **stack)
{
	if (!argv[i])
	{
		ft_printf("Error\n");
		return (0);
	}
	while (argv[i])
	{
		if (check_for_number(argv[i]) == -1 || check_for_integer(argv[i]) == -1)
		{
			ft_printf("Error\n");
			return (0);
		}
		*stack = ft_list_add_back((*stack), ft_atoi(argv[i++]), 0);
	}
	return (1);
}
