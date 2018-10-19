/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 17:25:30 by bopopovi          #+#    #+#             */
/*   Updated: 2018/10/19 18:41:57 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H

# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"

# define PRINT_ERROR_MSG 0

typedef _Bool t_bool;

typedef struct	s_stacks
{
	t_dlist		*a;
	t_dlist		*b;
	size_t		a_size;
	size_t		b_size;
}				t_stacks;

typedef struct	s_inst
{
	void		(*function)(t_stacks*);
	char		*name;
}				t_inst;

/*
** INPUT PARSING
*/

int				params_to_stack(char **params, t_dlist **head);
int				get_input(int ac, char **av, t_dlist **head_a);

/*
** MEM TOOLS
*/

void			del_stacks(t_stacks *stks);
void			init_stacks_container(t_stacks *container);
void			free_structures(t_stacks *stks, t_list **inst);

/*
** STACKS FUNCTIONS
*/

void			swap_a(t_stacks *stks);
void			swap_b(t_stacks *stks);
void			swap_ab(t_stacks *stks);
void			push_a(t_stacks *stks);
void			push_b(t_stacks *stks);
void			rotate_a(t_stacks *stks);
void			rotate_b(t_stacks *stks);
void			rotate_ab(t_stacks *stks);
void			reverse_rotate_a(t_stacks *stks);
void			reverse_rotate_b(t_stacks *stks);
void			reverse_rotate_ab(t_stacks *stks);

/*
** INSTRUCTION TOOLS
*/

void			rec_inst(char *name, t_list **inst, void (*val)(t_stacks*));
void			(*is_instruction(char *instruction))(t_stacks*);

/*
** COMPARISON TOOLS
*/

int				get_val(t_dlist *head);
int				is_greater(t_dlist *a, t_dlist *b);
int				is_smaller(t_dlist *a, t_dlist *b);
int				is_equal(t_dlist *a, t_dlist *b);
int				is_sorted(t_dlist *head, int ascending);

/*
** DEBUG
*/

int				put_error(char *msg, int return_value);
void			print_stack(t_dlist *head);
void			print_link_state(t_dlist *link);

#endif
