/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 17:25:30 by bopopovi          #+#    #+#             */
/*   Updated: 2018/09/27 18:43:25 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H

# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"

# define PRINT_ERROR_MSG 0

typedef _Bool t_bool;

typedef struct		s_stacks
{
	t_dlist			*head_a;
	t_dlist			*head_b;
	size_t			a_size;
	size_t			b_size;
}					t_stacks;

typedef struct		s_inst
{
	void			(*function)(t_stacks*);
	char			*name;
}					t_inst;

/*
** FUNCTIONS
*/

int			put_error(char *msg, int return_value);
int			params_to_stack(char **params, t_dlist **head);
int			get_input(int ac, char **av, t_dlist **head_a);
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
void		del_stacks(t_stacks *stacks);
void		init_stacks_container(t_stacks *container);
void		free_structures(t_stacks *stacks, t_list **inst);
void		record_instruction(char *name, t_list **inst, void (*val)(t_stacks*));
void		(*is_instruction(char *instruction))(t_stacks*);

#endif
