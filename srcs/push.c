/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 23:13:46 by bopopovi          #+#    #+#             */
/*   Updated: 2018/09/21 00:20:28 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "libft.h"

int		push_a(t_stacks *stacks)
{
	t_dlist		*tmp;

	tmp = NULL;
	if (stacks->head_b)
	{
		if (stacks->head_b == stacks->tail_b)
			stacks->head_b = NULL;
		tmp = ft_dlstpop(&(stacks->tail_b));
		ft_dlstadd(&(stacks->tail_a), tmp);
		if (!stacks->head_a)
			stacks->head_a = stacks->tail_a;
		if (stacks->tail_a->next)
			stacks->tail_a = stacks->tail_a->next;
	}
	return (0);
}

int		push_b(t_stacks *stacks)
{
	t_dlist		*tmp;

	tmp = NULL;
	if (stacks->head_a)
	{
		if (stacks->head_a == stacks->tail_a)
			stacks->head_a = NULL;
		tmp = ft_dlstpop(&(stacks->tail_a));
		ft_dlstadd(&(stacks->tail_b), tmp);
		if (!stacks->head_b)
			stacks->head_b = stacks->tail_b;
		if (stacks->tail_b->next)
			stacks->tail_b = stacks->tail_b->next;
	}
	return (0);
}
