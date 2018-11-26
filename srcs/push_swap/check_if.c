/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 15:38:41 by amelikia          #+#    #+#             */
/*   Updated: 2018/11/22 15:38:41 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_if(char *s1, char *s2)
{
	if ((!ft_strcmp(s1, "ra") && !ft_strcmp(s2, "rra")) ||
	(!ft_strcmp(s1, "rra") && !ft_strcmp(s2, "ra"))
	|| (!ft_strcmp(s1, "pb") && !ft_strcmp(s2, "pa")) ||
	(!ft_strcmp(s1, "pa") && !ft_strcmp(s2, "pb")) ||
	(!ft_strcmp(s1, "rb") && !ft_strcmp(s2, "rrb"))
	|| (!ft_strcmp(s1, "rrb") && !ft_strcmp(s2, "rb")))
		return (1);
	return (0);
}

void	if_check_if(t_comm **commands)
{
	if ((*commands)->next && (*commands)->next->next)
	{
		*commands = (*commands)->next;
		*commands = (*commands)->next;
	}
	else
		*commands = NULL;
}
