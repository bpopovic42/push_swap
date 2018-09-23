/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 16:33:17 by bopopovi          #+#    #+#             */
/*   Updated: 2018/09/21 16:35:50 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "libft.h"

void		reverse_rotate_a(t_stacks *stacks)
{
	if (stacks->head_a && stacks->head_a->prev)
		stacks->head_a = stacks->head_a->prev;
}

void		reverse_rotate_b(t_stacks *stacks)
{
	if (stacks->head_b && stacks->head_b->prev)
		stacks->head_b = stacks->head_b->prev;
}

void		reverse_rotate_ab(t_stacks *stacks)
{
	reverse_rotate_a(stacks);
	reverse_rotate_b(stacks);
}
