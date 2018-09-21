/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 17:25:30 by bopopovi          #+#    #+#             */
/*   Updated: 2018/09/21 23:00:04 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "libft.h"
# include <fcntl.h>
# include <unistd.h>

# define PRINT_ERROR_MSG 1

typedef _Bool t_bool;

typedef struct		s_flags
{
	t_bool			visualizer;
	t_bool			color;
}					t_flags;

typedef struct		s_stacks
{
	t_dlist			*head_a;
	t_dlist			*head_b;
}					t_stacks;

typedef struct		s_inst
{
	void			(*function)(t_stacks*);
	char			*name;
}					t_inst;

/*
** FUNCTIONS
*/

int			init_stack(char **params, t_dlist **head);
void		print_stack(t_dlist *head, char stack_name);
int			put_error(char *msg, int return_value);
t_dlist		*get_next_val_if_valid(char *value);
int			check_characters(char *str);
int			get_input(int ac, char **av, t_dlist **head_a, t_flags *flags);
int			get_instructions(t_list **inst);
int			execute_instructions(t_stacks *stacks, t_list **inst, t_flags *flags);
void		swap_a(t_stacks *stacks);
void		swap_b(t_stacks *stacks);
void		swap_ab(t_stacks *stacks);
void		push_a(t_stacks *stacks);
void		push_b(t_stacks *stacks);
void		rotate_a(t_stacks *stacks);
void		rotate_b(t_stacks *stacks);
void		rotate_ab(t_stacks *stacks);
void		reverse_rotate_a(t_stacks *stacks);
void		reverse_rotate_b(t_stacks *stacks);
void		reverse_rotate_ab(t_stacks *stacks);
void		del_instruction(void *inst, size_t size);

/*
** DEBUGGING
*/
void		print_link_state(t_dlist *link);

#endif
