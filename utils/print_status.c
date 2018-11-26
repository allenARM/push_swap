/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 15:42:56 by amelikia          #+#    #+#             */
/*   Updated: 2018/11/22 15:42:57 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	print_stack_a(t_list **stack_a, int printed_rows, int heigth, int color)
{
	int		max_length_a;

	max_length_a = find_max_length(*stack_a);
	if ((ft_list_size(*stack_a) + printed_rows) >= heigth)
	{
		if (color == 1)
			ft_printf("%s%-*d%s", RED, max_length_a + 1, \
					(*stack_a)->data, WHITE);
		if (color == 0)
			ft_printf("%-*d", max_length_a + 1, (*stack_a)->data);
		(*stack_a) = (*stack_a)->next;
	}
	else
		ft_printf("%-*c ", max_length_a, ' ');
}

void	print_stack_b(t_list **stack_b, int printed_rows, int heigth, int color)
{
	int		max_length_b;

	max_length_b = find_max_length(*stack_b);
	if ((ft_list_size(*stack_b) + printed_rows) >= heigth)
	{
		if (color == 0)
			ft_printf("%-*d", max_length_b, (*stack_b)->data);
		if (color == 1)
			ft_printf("%s%-*d%s", BLUE, max_length_b, (*stack_b)->data, WHITE);
		(*stack_b) = (*stack_b)->next;
	}
	ft_printf("\n");
}

void	print_status(t_list *stack_a, t_list *stack_b, int color)
{
	int		heigth;
	int		max_length_a;
	int		max_length_b;
	int		printed_rows;

	ft_printf("-------------------------\n");
	if (ft_list_size(stack_a) > ft_list_size(stack_b))
		heigth = ft_list_size(stack_a);
	else
		heigth = ft_list_size(stack_b);
	printed_rows = 0;
	max_length_a = find_max_length(stack_a);
	max_length_b = find_max_length(stack_b);
	while (heigth > printed_rows)
	{
		print_stack_a(&stack_a, printed_rows, heigth, color);
		print_stack_b(&stack_b, printed_rows, heigth, color);
		++printed_rows;
	}
	ft_printf("%-*c -\n", max_length_a, '-');
	ft_printf("%-*c b\n", max_length_a, 'a');
}
