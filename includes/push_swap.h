/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 19:45:57 by amelikia          #+#    #+#             */
/*   Updated: 2018/12/14 19:45:58 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "operations.h"

void				error_push_swap(int flag_optimized, t_list **stack);
int					find_solution(t_list **stack_a);
int					find_optimal_solution(t_list *stack_a, int flag_optimized);

int					search(t_list *stack_a, t_list *stack_b,
	int set_depth, t_comm **command_list);
int					swap_rec(t_list *stack_a, t_list *stack_b,
	int set_depth, t_comm **command_list);
int					push_rec(t_list *stack_a, t_list *stack_b,
	int set_depth, t_comm **command_list);
int					rotate_rec(t_list *stack_a, t_list *stack_b,
	int set_depth, t_comm **command_list);
int					reverse_rotate_rec(t_list *stack_a, t_list *stack_b,
	int set_depth, t_comm **command_list);
int					check_last_comm(t_comm *list, char *command);
int					check_answer(t_list *stack_a, t_list *stack_b);
int					count_reverse_rotate(t_list *stack, int pos);
int					count_rotate(t_list *stack, int pos);
void				reverse_rotate_until(t_list **stack, int pos);
void				rotate_until(t_list **stack, int pos);
void				find_and_apply_minimal_oper(t_list **stack_a,\
	t_list **stack_b);
void				assign_comm_ra_rb(t_minimal *min, t_comm **commands);
void				assign_comm_rra_rb(t_minimal *min, t_comm **commands);
void				assign_comm_ra_rrb(t_minimal *min, t_comm **commands);
void				assign_comm_rra_rrb(t_minimal *min, t_comm **commands);
void				count_rotate_rev_rotate(t_list *stack,\
	int pos, int *r, int *rr);
int					find_the_biggest_chain(t_list *stack_a);
int					find_the_last_number(t_list *stack_a);
void				define_biggest_chain(t_list **stack_a, int beginning_chain);
void				push_b_but_chain(t_list **stack_a,\
	t_list **stack_b);
int					find_number_of_zero_chain(t_list *stack);
void				apply_commands(t_list **stack_a, t_list **stack_b,\
	t_comm *commands_min);
void				deal_with_b(t_list **tmp, t_list *stack_b,\
	t_minimal *min, t_list *stack_a);
void				find_total(t_minimal *min, t_comm **commands);
void				set_minimal(t_minimal *min);
int					right_pos_in_a(t_list *stack_a, int pos);
int					return_minimal(int n1, int n2);
void				find_minimal(t_list *stack,\
	t_minimal *min, int pos, int id);
int					find_last_pos(t_list *stack);
int					find_pos(t_list *stack_a, int min_max);

#endif
