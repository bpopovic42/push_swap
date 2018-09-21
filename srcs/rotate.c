/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 16:30:16 by bopopovi          #+#    #+#             */
/*   Updated: 2018/09/21 16:33:05 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "libft.h"

void	rotate_a(t_stacks *stacks)
{
	if (stacks->head_a && stacks->head_a->next)
		stacks->head_a = stacks->head_a->next;
}

void	rotate_b(t_stacks *stacks)
{
	if (stacks->head_b && stacks->head_b->next)
		stacks->head_b = stacks->head_b->next;
}

void	rotate_ab(t_stacks *stacks)
{
	rotate_a(stacks);
	rotate_b(stacks);
}
