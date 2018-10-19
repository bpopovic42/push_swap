/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 22:12:30 by bopopovi          #+#    #+#             */
/*   Updated: 2018/10/19 18:43:49 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "common.h"

/*
** INSTRUCTION TOOLS
*/

void		exec_instruct(char *name, t_list **inst, t_stacks *stks);
void		exec_instruct_n(char *name, t_list **inst, t_stacks *stks, int n);

/*
** SORTING TOOLS
*/

int			get_median(t_dlist *head, size_t list_size, int div);
int			check_rotation(t_list **inst, t_stacks *stks);
int			get_highest(t_dlist *head, int *highest);
int			get_lowest(t_dlist *head, int *lowest);
size_t		get_highest_pos(t_dlist *head);
void		sort_a(t_list **inst, t_stacks *stks);
void		sort_b(t_list **inst, t_stacks *stks);
void		small_sort(t_list **inst, t_stacks *stks);

#endif
