/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 19:46:01 by amelikia          #+#    #+#             */
/*   Updated: 2018/12/14 19:46:02 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "../libft/libft.h"

# define RED "\x1B[31m"
# define BLUE "\x1B[34m"
# define WHITE "\x1B[39m"
# define CLEAN "\e[1;1H\e[2J"

typedef struct		s_list
{
	int				data;
	int				pos;
	int				if_chain;
	struct s_list	*next;
}					t_list;

typedef struct		s_comm
{
	char			*command;
	struct s_comm	*next;
}					t_comm;

typedef struct		s_minimal
{
	int				ra;
	int				rb;
	int				rra;
	int				rrb;
	int				rr;
	int				rrr;
	int				best_pos;
	int				best_total;
	int				current_total;
	t_comm			*commands;
}					t_minimal;

int					ft_list_size(t_list *root);
t_list				*ft_list_add_back(t_list *list,\
	int data, int pos, int if_chain);
t_list				*ft_list_add_front(t_list *list,\
	int data, int pos, int if_chain);
void				ft_list_clean(t_list **list);
t_list				*ft_list_dup(t_list *list);
t_list				*ft_list_ndup(t_list *list, int size);
void				ft_list_remove_back(t_list **list);
void				ft_list_remove_front(t_list **list);
int					find_max_length(t_list *list);
t_list				*list_assign_pos(t_list *stack);
t_comm				*ft_comm_add_front(t_comm *list, char *command);
t_comm				*ft_comm_add_back(t_comm *list, char *command);
void				ft_comm_remove_back(t_comm **list);
int					ft_comm_size(t_comm *root);
int					find_in_list(t_list *root, int num);
void				ft_comm_clean(t_comm **comm);
int					if_str_split(char **argv, t_list **stack, int *i);
int					add_to_list(int i, char **argv, t_list **stack);
int					color_and_status_check(char **argv,
			int *flag_c, int *flag_v, int *flag_o);
void				print_status(t_list *stack_a, t_list *stack_b, int color);
int					check_for_integer(char *str);
int					check_for_number(char *str);
int					check_for_duplicates(t_list *stack_a);
void				ft_list_clean_two(t_list **a, t_list **b);

#endif
