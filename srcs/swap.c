/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 19:22:32 by bopopovi          #+#    #+#             */
/*   Updated: 2018/09/21 15:03:48 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "libft.h"

int		swap_a(t_stacks *stacks)
{
	t_dlist		*swap;

	if (stacks->head_a && stacks->head_a->next)
	{
		swap = ft_dlstpop(stacks->head_a->next);
		ft_dlstpush(&(stacks->head_a), swap);
	}
	return (0);
}

int		swap_b(t_stacks *stacks)
{
	t_dlist		*swap;

	if (stacks->head_b && stacks->head_b->next)
	{
		swap = ft_dlstpop(stacks->head_b->next);
		ft_dlstpush(&(stacks->head_b), swap);
	}
	return (0);
}

int		swap_ab(t_stacks *stacks)
{
	swap_a(stacks);
	swap_b(stacks);
	return (0);
}
