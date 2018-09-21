/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 19:22:32 by bopopovi          #+#    #+#             */
/*   Updated: 2018/09/21 23:00:16 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "libft.h"
#include "ft_printf.h"

void	swap_a(t_stacks *stacks)
{
	t_dlist		*swap;

	if (stacks->head_a && stacks->head_a->next)
	{
		swap = ft_dlstpop(stacks->head_a->next);
		ft_dlstpush(&(stacks->head_a), swap);
	}
}

void	swap_b(t_stacks *stacks)
{
	t_dlist		*swap;

	if (stacks->head_b && stacks->head_b->next)
	{
		swap = ft_dlstpop(stacks->head_b->next);
		ft_dlstpush(&(stacks->head_b), swap);
	}
}

void	swap_ab(t_stacks *stacks)
{
	swap_a(stacks);
	swap_b(stacks);
}
