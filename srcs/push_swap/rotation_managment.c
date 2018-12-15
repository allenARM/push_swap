/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_managment.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 17:27:40 by amelikia          #+#    #+#             */
/*   Updated: 2018/12/14 17:53:37 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		count_reverse_rotate(t_list *stack, int pos)
{
	int		count;
	t_list	*temp;

	temp = ft_list_dup(stack);
	count = 0;
	while (temp->pos != pos)
	{
		reverse_rotate(&temp);
		++count;
	}
	ft_list_clean(&temp);
	return (count);
}

int		count_rotate(t_list *stack, int pos)
{
	int		count;
	t_list	*temp;

	temp = ft_list_dup(stack);
	count = 0;
	while (temp->pos != pos)
	{
		rotate(&temp);
		++count;
	}
	ft_list_clean(&temp);
	return (count);
}

void	reverse_rotate_until(t_list **stack, int pos)
{
	while ((*stack)->pos != pos)
		reverse_rotate(stack);
}

void	rotate_until(t_list **stack, int pos)
{
	while ((*stack)->pos != pos)
		rotate(stack);
}

void	count_rotate_rev_rotate(t_list *stack, int pos, int *r, int *rr)
{
	int i;
	int stack_size;

	stack_size = ft_list_size(stack);
	i = 0;
	while (stack->pos != pos && stack)
	{
		i++;
		stack = stack->next;
	}
	*r = i;
	if (i != 0)
		*rr = (stack_size) - i;
	else
		*rr = 0;
}
