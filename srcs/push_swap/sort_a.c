/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 17:32:17 by bopopovi          #+#    #+#             */
/*   Updated: 2018/10/19 18:16:11 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	dist_to_val_under_m(t_dlist *head, int m)
{
	t_dlist *ptr;
	t_dlist *ptr2;
	size_t	distance;

	ptr = NULL;
	ptr2 = NULL;
	distance = 0;
	while (ptr != head)
	{
		if (!ptr && !ptr2)
		{
			ptr = head->next;
			ptr2 = head->prev;
		}
		if ((get_val(ptr) <= m || get_val(ptr2) <= m))
		{
			return (distance);
		}
		ptr = ptr->next;
		ptr2 = ptr2->prev;
		distance++;
	}
	return (distance);
}

static char		*get_closest_rotation_under_m(t_dlist *head, int m)
{
	t_dlist *ptr;
	t_dlist *ptr2;

	ptr = NULL;
	ptr2 = NULL;
	while (ptr != head)
	{
		if (ptr && (get_val(ptr) <= m || get_val(ptr2) <= m))
			break ;
		ptr = !ptr ? head->next : ptr->next;
		ptr2 = !ptr2 ? head->prev : ptr2->prev;
	}
	if (get_val(ptr) <= m)
		return ("ra");
	return ("rra");
}

static int		count_val_under_m(t_dlist *head, int m)
{
	t_dlist		*ptr;
	int			count;

	ptr = NULL;
	count = 0;
	while (ptr != head)
	{
		if (!ptr)
			ptr = head;
		count += get_val(ptr) <= m ? 1 : 0;
		ptr = ptr->next;
	}
	return (count);
}

static void		push_next_under_m(t_stacks *stks, t_list **inst, int m, int lm)
{
	char	*rot;
	int		rot_b_len;

	rot = get_closest_rotation_under_m(stks->a, m);
	rot_b_len = 0;
	while (get_val(stks->a) > m)
	{
		exec_instruct(rot, inst, stks);
		if (rot_b_len)
		{
			rot_b_len--;
			if (!ft_strcmp("ra", rot))
				exec_instruct("rb", inst, stks);
			else
				exec_instruct("rrb", inst, stks);
		}
	}
	exec_instruct("pb", inst, stks);
	if (get_val(stks->b) < lm)
	{
		if (dist_to_val_under_m(stks->a, m) >= stks->b_size - 1)
			rot_b_len = stks->b_size - 1;
		else
			exec_instruct("rb", inst, stks);
	}
}

void			sort_a(t_list **inst, t_stacks *stks)
{
	int median;
	int lower_median;
	int under_median;

	if (stks->a_size > 5)
	{
		median = get_median(stks->a, stks->a_size, 5);
		lower_median = get_median(stks->a, stks->a_size, 10);
		under_median = count_val_under_m(stks->a, median);
		while (under_median--)
			push_next_under_m(stks, inst, median, lower_median);
		sort_a(inst, stks);
	}
	else
		small_sort(inst, stks);
}
