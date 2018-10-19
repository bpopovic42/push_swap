/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 16:19:25 by bopopovi          #+#    #+#             */
/*   Updated: 2018/10/19 18:16:55 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		get_highests(t_dlist *head, int high[3])
{
	t_dlist *ptr;

	ptr = NULL;
	high[0] = get_val(head);
	high[1] = get_val(head);
	high[2] = get_val(head);
	while (ptr != head)
	{
		if (!ptr)
			ptr = head;
		if (get_val(ptr) > high[0])
		{
			high[2] = high[1];
			high[1] = high[0];
			high[0] = get_val(ptr);
		}
		else if (get_val(ptr) > high[1] && get_val(ptr) < high[0])
		{
			high[2] = high[1];
			high[1] = get_val(ptr);
		}
		else if (get_val(ptr) > high[2] && get_val(ptr) < high[1])
			high[2] = get_val(ptr);
		ptr = ptr->next;
	}
}

static void		sort_top_three_val(t_stacks *stks, t_list **inst)
{
	if (is_smaller(stks->a->next, stks->a))
		exec_instruct("sa", inst, stks);
	if (is_smaller(stks->a->next->next, stks->a->next))
	{
		exec_instruct("ra", inst, stks);
		exec_instruct("sa", inst, stks);
		exec_instruct("rra", inst, stks);
	}
}

static void		push_highests(t_stacks *stks, t_list **inst, char *rot)
{
	int hi[3];

	get_highests(stks->b, hi);
	while (get_val(stks->b) != hi[0])
	{
		if (get_val(stks->b) == hi[1])
			exec_instruct("pa", inst, stks);
		else if (get_val(stks->a) == hi[1] && get_val(stks->b) == hi[2])
			exec_instruct("pa", inst, stks);
		else
			exec_instruct(rot, inst, stks);
	}
	exec_instruct("pa", inst, stks);
	sort_top_three_val(stks, inst);
}

void			sort_b(t_list **inst, t_stacks *stks)
{
	size_t pos;

	while (stks->b)
	{
		pos = get_highest_pos(stks->b);
		if (pos > (stks->b_size / 2))
			push_highests(stks, inst, "rrb");
		else
			push_highests(stks, inst, "rb");
	}
}
