/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstpop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 15:01:06 by bopopovi          #+#    #+#             */
/*   Updated: 2018/09/21 00:05:01 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist		*ft_dlstpop(t_dlist **alst)
{
	t_dlist		*tmp;

	tmp = NULL;
	if (alst && *alst)
	{
		tmp = *alst;
		if (!tmp->next || !tmp->prev)
		{
			if (!tmp->next)
				*alst = tmp->prev;
			else
				*alst = tmp->next;
		}
		else
			*alst = NULL;
		if (tmp->next)
			tmp->next->prev = tmp->prev;
		if (tmp->prev)
			tmp->prev->next = tmp->next;
		tmp->next = NULL;
		tmp->prev = NULL;
	}
	return (tmp);
}
