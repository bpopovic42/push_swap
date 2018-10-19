/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 16:29:59 by bopopovi          #+#    #+#             */
/*   Updated: 2018/10/19 18:18:03 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"
#include "push_swap.h"

size_t	get_highest_pos(t_dlist *head)
{
	t_dlist		*ptr;
	int			tmp;
	int			i;
	int			pos;

	head->prev->next = NULL;
	ptr = head;
	tmp = get_val(head);
	i = 0;
	pos = 0;
	while (ptr)
	{
		if (get_val(ptr) > tmp)
		{
			pos = i;
			tmp = get_val(ptr);
		}
		i++;
		ptr = ptr->next;
	}
	head->prev->next = head;
	return (pos);
}

int		get_highest(t_dlist *head, int *highest)
{
	t_dlist		*ptr;

	if (head)
	{
		ptr = head->next;
		if (head && head->prev)
			head->prev->next = NULL;
		*highest = get_val(head);
		while (ptr)
		{
			if (*highest < get_val(ptr))
				*highest = get_val(ptr);
			ptr = ptr->next;
		}
		if (head && head->prev)
			head->prev->next = head;
	}
	return (0);
}

int		check_rotation(t_list **inst, t_stacks *stks)
{
	t_dlist		*ptr;
	size_t		i;

	ptr = stks->a;
	i = 0;
	while (i < stks->a_size && !is_sorted(ptr, 1))
	{
		i++;
		ptr = ptr->next;
	}
	if (is_sorted(ptr, 1))
	{
		if (i > (stks->a_size / 2))
			exec_instruct_n("rra", inst, stks, stks->a_size - i);
		else
			exec_instruct_n("ra", inst, stks, i);
		return (1);
	}
	return (0);
}

int		get_lowest(t_dlist *head, int *lowest)
{
	t_dlist		*ptr;

	if (head)
	{
		ptr = head->next;
		if (head && head->prev)
			head->prev->next = NULL;
		*lowest = get_val(head);
		while (ptr)
		{
			if (*lowest > get_val(ptr))
				*lowest = (int)get_val(ptr);
			ptr = ptr->next;
		}
		if (head && head->prev)
			head->prev->next = head;
	}
	return (0);
}
