/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 16:28:27 by bopopovi          #+#    #+#             */
/*   Updated: 2018/10/19 18:13:36 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		locate_value(t_dlist *head, int val)
{
	t_dlist		*ptr;
	int			i;

	ptr = head;
	i = 0;
	while (ptr != head || !i)
	{
		if (get_val(ptr) == val)
			break ;
		i++;
		ptr = ptr->next;
	}
	return (i);
}

static void		get_rotation_type(size_t size, size_t *rot, char **type)
{
	if (*rot > (size / 2))
	{
		*rot = (size - *rot);
		*type = "rra";
	}
	else
		*type = "ra";
}

static void		push_a_lowest_n(t_list **inst, t_stacks *stks, int n)
{
	int			lowest;
	size_t		rot;
	char		*rot_type;

	while (n)
	{
		get_lowest(stks->a, &lowest);
		rot = locate_value(stks->a, lowest);
		get_rotation_type(stks->a_size, &rot, &rot_type);
		exec_instruct_n(rot_type, inst, stks, rot);
		exec_instruct("pb", inst, stks);
		n--;
	}
}

void			small_sort(t_list **inst, t_stacks *stks)
{
	int repush;

	repush = 0;
	if (!is_sorted(stks->a, 1))
	{
		if (!check_rotation(inst, stks))
		{
			if (stks->a_size > 3)
			{
				repush += 2;
				push_a_lowest_n(inst, stks, 2);
			}
			if (!check_rotation(inst, stks))
				exec_instruct("sa", inst, stks);
			if (stks->b && stks->b->next && is_smaller(stks->b, stks->b->next))
				exec_instruct("sb", inst, stks);
			check_rotation(inst, stks);
			exec_instruct_n("pa", inst, stks, repush);
		}
	}
}
