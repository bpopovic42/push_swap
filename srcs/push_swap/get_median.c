/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_median.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 16:15:02 by bopopovi          #+#    #+#             */
/*   Updated: 2018/09/23 16:20:53 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		get_input_size(t_stacks *stacks)
{
	size_t	size;
	t_dlist	*ptr;

	size = 0;
	if (stacks->head_a && stacks->head_a->next)
	{
		stacks->head_a->prev->next = NULL;
		ptr = stacks->head_a;
		while (ptr)
		{
			size++;
			ptr = ptr->next;
		}
		stacks->head_a->prev->next = stacks->head_a;
	}
	else if (stacks->head_a)
		return (1);
	return (size);
}


static int		is_median(t_dlist *head, int value, size_t half)
{
	t_dlist		*ptr;
	size_t		count;

	ptr = head;
	count = 0;
	while (ptr)
	{
		if ((int)*((int*)ptr->content) < value)
			count++;
		ptr = ptr->next;
	}
	return (count == half);
}

int		get_median(t_stacks *stacks)
{
	size_t		list_size;
	size_t		half;
	t_dlist		*ptr;

	list_size = get_input_size(stacks);
	half = list_size % 2 == 0 ? (list_size / 2) - 1 : list_size / 2;
	ptr = stacks->head_a;
	stacks->head_a->prev->next = NULL;
	while (ptr && !is_median(stacks->head_a, (int)*((int*)ptr->content), half))
		ptr = ptr->next;
	stacks->head_a->prev->next = stacks->head_a;
	return ((int)*((int*)ptr->content));
}
