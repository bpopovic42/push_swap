/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstswap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 00:08:38 by bopopovi          #+#    #+#             */
/*   Updated: 2018/09/20 01:46:54 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void		ft_dlstswap(t_dlist **a, t_dlist **b)
{
	t_dlist		*ptr;
	t_dlist		*next;
	t_dlist		*prev;

	next = (*a)->next;
	prev = (*a)->prev;
	ptr = *a;
	if ((*b)->next)
		(*b)->next->prev = (*a);
	if ((*b)->prev)
		(*b)->prev->next = (*a);
	*a = *b;
	*b = ptr;
	if (next)
		next->prev = (*b);
	if (prev)
		prev->next = (*b);
	(*b)->next = (*a)->next;
	(*b)->prev = (*a)->prev;
	(*a)->next = next;
	(*a)->prev = prev;
}
