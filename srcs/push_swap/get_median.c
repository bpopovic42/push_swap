/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_median.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 16:15:02 by bopopovi          #+#    #+#             */
/*   Updated: 2018/10/19 18:13:20 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		is_median(t_dlist *head, int value, size_t half)
{
	t_dlist		*ptr;
	size_t		count;

	ptr = head;
	count = 0;
	while (ptr)
	{
		if (get_val(ptr) < value)
			count++;
		ptr = ptr->next;
	}
	return (count == half);
}

int				get_median(t_dlist *head, size_t list_size, int div)
{
	size_t		half;
	t_dlist		*ptr;

	half = list_size / div;
	ptr = head;
	head->prev->next = NULL;
	while (ptr && !is_median(head, get_val(ptr), half))
		ptr = ptr->next;
	head->prev->next = head;
	return (get_val(ptr));
}
