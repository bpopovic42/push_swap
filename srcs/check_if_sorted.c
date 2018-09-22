/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_sorted.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 10:35:51 by bopopovi          #+#    #+#             */
/*   Updated: 2018/09/22 10:59:19 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "libft.h"

static int		success(void)
{
	ft_putstr("OK\n");
	return (1);
}

static int		failure(void)
{
	ft_putstr("KO\n");
	return (0);
}

int		check_if_sorted(t_stacks *stacks)
{
	t_dlist		*ptr;

	if (!stacks->head_b)
	{
		if (stacks->head_a)
		{
			if (stacks->head_a->prev)
				stacks->head_a->prev->next = NULL;
			else
				return (success());
			ptr = stacks->head_a->next;
			while (ptr)
			{
				if ((int)*((int*)ptr->prev->content) > (int)*((int*)ptr->content))
					return (failure());
				ptr = ptr->next;
			}
			return (success());
		}
		else
			return (success());
	}
	return (failure());
}
