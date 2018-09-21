/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 17:25:30 by bopopovi          #+#    #+#             */
/*   Updated: 2018/09/21 00:14:22 by bopopovi         ###   ########.fr       */
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
	t_dlist			*tail_a;
	t_dlist			*head_b;
	t_dlist			*tail_b;
}					t_stacks;

typedef struct		s_instruction
{
	void			(*function)(t_stacks*);
	char			*name;
}					t_instruction;

/*
** FUNCTIONS
*/

int			init_stack(char **params, t_dlist **head, t_dlist **tail);
void		print_stack(t_dlist *head, char stack_name);
int			put_error(char *msg, int return_value);
int			get_next_val_if_valid(t_dlist *ptr, char *value);
int			check_characters(char *str);
int			get_input(int ac, char **av, t_dlist **head_a, t_dlist **tail_a, t_flags *flags);
int			get_instructions(t_list **instructions);
int			execute_instructions(t_stacks *stacks, t_list **inst, t_flags *flags);
int			swap_a(t_stacks *stacks);
int			swap_b(t_stacks *stacks);
int			push_a(t_stacks *stacks);
int			push_b(t_stacks *stacks);

#endif
