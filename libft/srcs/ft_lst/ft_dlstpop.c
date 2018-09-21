/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstpop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 15:01:06 by bopopovi          #+#    #+#             */
/*   Updated: 2018/09/21 12:49:28 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist		*ft_dlstpop(t_dlist *elem)
{
	t_dlist		*tmp;

	tmp = NULL;
	if (elem)
	{
		tmp = elem;
		if (tmp->next)
			tmp->next->prev = tmp->prev;
		if (tmp->prev)
			tmp->prev->next = tmp->next;
		tmp->next = NULL;
		tmp->prev = NULL;
	}
	return (tmp);
}
