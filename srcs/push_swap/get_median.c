/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_median.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 16:15:02 by bopopovi          #+#    #+#             */
/*   Updated: 2018/10/02 18:32:04 by bopopovi         ###   ########.fr       */
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
		if ((int)*((int*)ptr->content) < value)
			count++;
		ptr = ptr->next;
	}
	return (count == half);
}

int		get_list_len(t_dlist *head)
{
	t_dlist *ptr;
	int i;

	i = 0;
	if (head)
	{
		if (head->prev)
		{
			head->prev->next = NULL;
			ptr = head;
			while (ptr)
			{
				ptr = ptr->next;
				i++;
			}
			head->prev->next = head;
		}
		else
			return (1);
	}
	return (i);
}

int		get_median(t_dlist *head)
{
	size_t		list_size;
	size_t		half;
	t_dlist		*ptr;

	list_size = get_list_len(head);
	half = list_size / 2;
	ptr = head;
	head->prev->next = NULL;
	while (ptr && !is_median(head, (int)*((int*)ptr->content), half))
		ptr = ptr->next;
	head->prev->next = head;
//	if (ptr)
		return ((int)*((int*)ptr->content));
//	else
//		return (*((int*)head->content));
}
