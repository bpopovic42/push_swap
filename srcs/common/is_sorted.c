/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 10:35:51 by bopopovi          #+#    #+#             */
/*   Updated: 2018/10/18 19:33:49 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

int		is_sorted(t_dlist *head, int ascending)
{
	t_dlist		*ptr;

	if (head)
	{
		if (!head->prev)
			return (1);
		ptr = head->next;
		while (ptr != head)
		{
			if (is_smaller(ptr->prev, ptr) && !ascending)
				return (0);
			else if (!is_smaller(ptr->prev, ptr) && ascending)
				return (0);
			ptr = ptr->next;
		}
	}
	return (1);
}
