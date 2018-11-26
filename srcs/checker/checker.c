/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 15:37:41 by amelikia          #+#    #+#             */
/*   Updated: 2018/11/22 15:37:41 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		exception_flag_o(t_list **stack, int flag_o)
{
	if (flag_o == 1)
	{
		write(2, "Error\n", 6);
		ft_list_clean(stack);
		return (0);
	}
	return (1);
}

int		main(int argc, char **argv)
{
	int		i;
	int		flag_v;
	int		flag_c;
	int		flag_o;
	t_list	*stack;

	flag_v = 0;
	flag_c = 0;
	flag_o = 0;
	stack = NULL;
	if (argc >= 2)
	{
		i = color_and_status_check(argv, &flag_c, &flag_v, &flag_o);
		if (if_str_split(argv, &stack, &i) == 0)
			return (0);
	}
	if (exception_flag_o(&stack, flag_o) == 0)
		return (0);
	error_checker(argc, flag_c, flag_v, &stack);
	ft_list_clean(&stack);
}
