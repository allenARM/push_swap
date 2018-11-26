/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fix_double_rotations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 15:39:14 by amelikia          #+#    #+#             */
/*   Updated: 2018/11/22 15:40:31 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char		*find_replacement_command(char *s1)
{
	if (ft_strlen(s1) == 2)
		return ("rr");
	else if (ft_strlen(s1) == 3)
		return ("rrr");
	else
		return (NULL);
}

int			count_occurences(t_comm **commands, char *str)
{
	int		i;

	i = 0;
	while (*commands && !ft_strcmp((*commands)->command, str))
	{
		i++;
		(*commands) = (*commands)->next;
	}
	return (i);
}

void		while_loop_adding(t_comm **new, int i, char *str)
{
	while (i)
	{
		*new = ft_comm_add_back(*new, str);
		--i;
	}
}

void		fix_double_rotations(char *s1, char *s2, \
				t_comm **commands, t_comm **new)
{
	char	*s3;
	int		i1;
	int		i2;

	s3 = find_replacement_command(s1);
	i1 = count_occurences(commands, s1);
	if (!(*commands) || ft_strcmp((*commands)->command, s2))
	{
		while_loop_adding(new, i1, s1);
		if (*commands)
			*new = ft_comm_add_back(*new, (*commands)->command);
		return ;
	}
	i2 = count_occurences(commands, s2);
	if (i1 >= i2)
	{
		while_loop_adding(new, i1 - i2, s1);
		while_loop_adding(new, i2, s3);
	}
	else
	{
		while_loop_adding(new, i1, s3);
		while_loop_adding(new, i2 - i1, s2);
	}
	*new = ft_comm_add_back(*new, (*commands)->command);
}
