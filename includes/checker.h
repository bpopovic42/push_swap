/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 17:25:30 by bopopovi          #+#    #+#             */
/*   Updated: 2018/09/19 04:18:20 by bopopovi         ###   ########.fr       */
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

typedef struct		s_stack
{
	struct s_stack	*prev;
	struct s_stack	*next;
	int				val;
}					t_stack;

typedef struct		s_ptr
{
	t_stack			*head_a;
	t_stack			*tail_a;
	t_stack			*head_b;
	t_stack			*tail_b;
}					t_ptr;

/*
** FUNCTIONS
*/

int			init_stack(char **params, t_stack **head);
void		print_stack(t_stack *head);
t_stack		*stack_new(int val);
void		del_stack(t_stack **stack);
void		delone_stack(t_stack **stack);
int			put_error(char *msg, int return_value);
int			get_next_val_if_valid(t_stack *ptr, char *value);
int			check_characters(char *str);
int			get_input(int ac, char **av, t_stack **head_a, t_flags *flags);
int			get_instructions(t_list **instructions);
int			execute_instructions(t_ptr *stacks, t_list **inst, t_flags *flags);

#endif
