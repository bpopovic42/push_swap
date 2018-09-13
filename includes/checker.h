/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 17:25:30 by bopopovi          #+#    #+#             */
/*   Updated: 2018/09/13 18:50:37 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <fcntl.h>
# include <unistd.h>

typedef struct		s_stack
{
	struct s_stack	*prev;
	struct s_stack	*next;
	int				val;
}					t_stack;

/*
** FUNCTIONS
*/

int			init_stack(t_stack *head, int ac, char **av);
void		print_stack(t_stack *head);
t_stack		*stack_new(int val);
void		del_stack(t_stack **stack);
void		delone_stack(t_stack **stack);
void		put_error(char *msg);
int			get_next_val_if_valid(t_stack *ptr, char *value);

#endif
