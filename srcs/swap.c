/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 19:22:32 by bopopovi          #+#    #+#             */
/*   Updated: 2018/09/21 12:48:45 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "libft.h"

int		swap_a(t_stacks *stacks)
{
	t_dlist		*a;
	t_dlist		*swap;

	a = stacks->tail_a;
	swap = ft_dlstpop(a->prev);
	ft_dlstadd(&a, swap);
	stacks->tail_a = swap;
	return (0);
}

int		swap_b(t_stacks *stacks)
{
	t_dlist		*b;
	t_dlist		*swap;

	b = stacks->tail_b;
	swap = ft_dlstpop(b->prev);
	ft_dlstadd(&b, swap);
	stacks->tail_b = swap;
	return (0);
}

int		swap_ab(t_stacks *stacks)
{
	swap_a(stacks);
	swap_b(stacks);
	return (0);
}
