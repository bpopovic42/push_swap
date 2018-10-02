/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 22:12:30 by bopopovi          #+#    #+#             */
/*   Updated: 2018/09/23 16:21:47 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "common.h"

/*
** FUNCTIONS
*/

int			get_median(t_stacks *stacks);
void		sort_stacks(t_stacks *stacks, t_list **inst, int median);

#endif