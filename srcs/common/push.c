/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 23:13:46 by bopopovi          #+#    #+#             */
/*   Updated: 2018/09/28 17:16:09 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "libft.h"

void	push_a(t_stacks *stacks)
{
	t_dlist		*tmp;
	t_dlist		*ptr;

	tmp = NULL;
	ptr = NULL;
	if (stacks->head_b)
	{
		ptr = stacks->head_b;
		if (stacks->head_b->next)
			stacks->head_b = stacks->head_b->next;
		else
			stacks->head_b = NULL;
		tmp = ft_dlstpop(ptr);
		ft_dlstpush(&(stacks->head_a), tmp);
	}
	if (stacks->head_b == tmp)
		stacks->head_b = NULL;
	else if (!stacks->head_a->prev)
	{
		stacks->head_a->prev = tmp;
		tmp->next = stacks->head_a;
	}
}

void	push_b(t_stacks *stacks)
{
	t_dlist		*tmp;
	t_dlist		*ptr;

	tmp = NULL;
	ptr = NULL;
	if (stacks->head_a)
	{
		ptr = stacks->head_a;
		if (stacks->head_a->next)
			stacks->head_a = stacks->head_a->next;
		else
			stacks->head_a = NULL;
		tmp = ft_dlstpop(ptr);
		ft_dlstpush(&(stacks->head_b), tmp);
	}
	if (stacks->head_a == tmp)
		stacks->head_a = NULL;
	else if (!stacks->head_b->prev)
	{
		stacks->head_b->prev = tmp;
		tmp->next = stacks->head_b;
	}
}
