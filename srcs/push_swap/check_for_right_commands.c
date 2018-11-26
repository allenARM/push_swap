/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_for_right_commands.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 15:38:33 by amelikia          #+#    #+#             */
/*   Updated: 2018/11/22 15:38:34 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_for_right_commnds(t_comm *commands)
{
	if (!commands->next)
		return (1);
	while (commands->next)
	{
		if ((!ft_strcmp(commands->command, "ra") &&
		!ft_strcmp(commands->next->command, "rra")) ||
		(!ft_strcmp(commands->command, "rra") &&
		!ft_strcmp(commands->next->command, "ra"))
		|| (!ft_strcmp(commands->command, "pb") &&
		!ft_strcmp(commands->next->command, "pa")) ||
		(!ft_strcmp(commands->command, "pa") &&
		!ft_strcmp(commands->next->command, "pb")) ||
		(!ft_strcmp(commands->command, "rb") &&
		!ft_strcmp(commands->next->command, "rrb"))
		|| (!ft_strcmp(commands->command, "rrb") &&
		!ft_strcmp(commands->next->command, "rb")))
			return (0);
		commands = commands->next;
	}
	return (1);
}
