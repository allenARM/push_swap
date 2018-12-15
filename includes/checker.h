/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 19:45:49 by amelikia          #+#    #+#             */
/*   Updated: 2018/12/14 19:45:50 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "operations.h"

int		read_output(t_list **stack_a, int flag_v, int flag_c);
void	check_result(t_list **stack_a, t_list **stack_b);
void	error_checker(int argc, int flag_c, int flag_v, t_list **stack);

#endif
