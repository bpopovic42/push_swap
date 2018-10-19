/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 19:22:32 by bopopovi          #+#    #+#             */
/*   Updated: 2018/10/18 18:54:07 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "libft.h"

void	swap_a(t_stacks *stks)
{
	t_dlist		*swap;

	if (stks->a && stks->a->next)
	{
		swap = ft_dlstpop(stks->a->next);
		ft_dlstpush(&(stks->a), swap);
	}
}

void	swap_b(t_stacks *stks)
{
	t_dlist		*swap;

	if (stks->b && stks->b->next)
	{
		swap = ft_dlstpop(stks->b->next);
		ft_dlstpush(&(stks->b), swap);
	}
}

void	swap_ab(t_stacks *stks)
{
	swap_a(stks);
	swap_b(stks);
}
