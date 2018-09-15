/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 17:25:30 by bopopovi          #+#    #+#             */
/*   Updated: 2018/09/16 01:34:49 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <fcntl.h>
# include <unistd.h>

typedef _Bool t_bool;

typedef struct		s_flags
{
	t_bool			visualizer;
	t_bool			color;
}					t_flags;

typedef struct		s_stack
{
	struct s_stack	*prev;
	struct s_stack	*next;
	int				val;
}					t_stack;

/*
** FUNCTIONS
*/

t_stack		*init_stack(int ac, char **av);
void		print_stack(t_stack *head);
t_stack		*stack_new(int val);
void		del_stack(t_stack **stack);
void		delone_stack(t_stack **stack);
void		put_error(char *msg);
int			get_next_val_if_valid(t_stack *ptr, char *value);
int			is_only_digits(char *str);
int			get_input(int ac, char **av, t_stack **head_a, t_flags *flags);

#endif
