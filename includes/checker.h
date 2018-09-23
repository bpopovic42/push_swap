/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 17:25:30 by bopopovi          #+#    #+#             */
/*   Updated: 2018/09/23 19:52:43 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "common.h"
# include <fcntl.h>
# include <unistd.h>

typedef struct		s_flags
{
	t_bool			visualizer;
	t_bool			color;
}					t_flags;

/*
** FUNCTIONS
*/

int			get_flags(int ac, char **av, t_flags *flags);
int			put_error(char *msg, int return_value);
int			check_characters(char *str);
int			get_instructions(t_list **inst);
int			execute_instructions(t_stacks *stacks, t_list **inst, t_flags *flags);
void		del_instruction(void *inst, size_t size);
int			check_if_sorted(t_stacks *stacks);
void		display(t_stacks *stacks, char *instruction, int color);

/*
** DEBUGGING
*/

void		print_link_state(t_dlist *link);

#endif
