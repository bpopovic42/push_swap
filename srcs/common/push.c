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

void	push_a(t_stacks *stks)
{
	t_dlist		*tmp;
	t_dlist		*ptr;

	tmp = NULL;
	ptr = NULL;
	if (stks->b)
	{
		ptr = stks->b;
		if (stks->b->next)
			stks->b = stks->b->next;
		else
			stks->b = NULL;
		tmp = ft_dlstpop(ptr);
		ft_dlstpush(&(stks->a), tmp);
	}
	if (stks->b == tmp)
		stks->b = NULL;
	else if (!stks->a->prev)
	{
		stks->a->prev = tmp;
		tmp->next = stks->a;
	}
}

void	push_b(t_stacks *stks)
{
	t_dlist		*tmp;
	t_dlist		*ptr;

	tmp = NULL;
	ptr = NULL;
	if (stks->a)
	{
		ptr = stks->a;
		if (stks->a->next)
			stks->a = stks->a->next;
		else
			stks->a = NULL;
		tmp = ft_dlstpop(ptr);
		ft_dlstpush(&(stks->b), tmp);
	}
	if (stks->a == tmp)
		stks->a = NULL;
	else if (!stks->b->prev)
	{
		stks->b->prev = tmp;
		tmp->next = stks->b;
	}
}
