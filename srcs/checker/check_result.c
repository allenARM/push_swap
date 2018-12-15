/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_result.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 19:46:30 by amelikia          #+#    #+#             */
/*   Updated: 2018/12/14 19:46:31 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void		check_result(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	tmp = *stack_a;
	if (*stack_b)
	{
		ft_printf("KO\n");
		ft_list_clean(stack_b);
		return ;
	}
	while (tmp->next)
	{
		if (tmp->data > tmp->next->data)
		{
			ft_printf("KO\n");
			return ;
		}
		tmp = tmp->next;
	}
	ft_printf("OK\n");
}
