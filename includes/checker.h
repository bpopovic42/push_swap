/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 17:25:30 by bopopovi          #+#    #+#             */
/*   Updated: 2018/10/19 18:43:08 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "common.h"
# include <fcntl.h>
# include <unistd.h>

typedef struct	s_flags
{
	t_bool		visualizer;
	t_bool		color;
}				t_flags;

/*
** INPUT HANDLING
*/

int				get_flags(int ac, char **av, t_flags *flags);
int				check_characters(char *str);
int				get_instructions(t_list **inst);
void			exec_inst(t_stacks *stks, t_list **inst, t_flags *flags);
void			del_instruction(void *inst, size_t size);

/*
** DISPLAY
*/

void			display(t_stacks *stks, char *instruction, int color);

/*
** ERROR
*/

int				put_error(char *msg, int return_value);

#endif
