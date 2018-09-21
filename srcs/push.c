/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 23:13:46 by bopopovi          #+#    #+#             */
/*   Updated: 2018/09/21 12:53:19 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "libft.h"

int		push_a(t_stacks *stacks)
{
	t_dlist		*tmp;
	t_dlist		*ptr;

	tmp = NULL;
	ptr = NULL;
	if (stacks->head_b)
	{
		if (stacks->head_b == stacks->tail_b)
		{
			stacks->head_b = NULL;
			ptr = stacks->tail_b;
		}
		else
		{
			ptr = stacks->tail_b;
			stacks->tail_b = stacks->tail_b->prev;
		}
		tmp = ft_dlstpop(ptr);
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
	t_dlist		*ptr;

	tmp = NULL;
	ptr = NULL;
	if (stacks->head_a)
	{
		if (stacks->head_a == stacks->tail_a)
		{
			stacks->head_a = NULL;
			ptr = stacks->tail_a;
		}
		else
		{
			ptr = stacks->tail_a;
			stacks->tail_a = stacks->tail_a->prev;
		}
		tmp = ft_dlstpop(ptr);
		ft_dlstadd(&(stacks->tail_b), tmp);
		if (!stacks->head_b)
			stacks->head_b = stacks->tail_b;
		if (stacks->tail_b->next)
			stacks->tail_b = stacks->tail_b->next;
	}
	return (0);
}
