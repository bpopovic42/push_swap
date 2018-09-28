/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 16:19:25 by bopopovi          #+#    #+#             */
/*   Updated: 2018/09/27 19:07:46 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		check_rotation(t_dlist *head)
{
	t_dlist		*ptr;
	int			index;
	int			count;
	int			i;

	ptr = head->next;
	index = 0;
	count = 0;
	i = 0;
	while (ptr)
	{
		if ((int)*((int*)ptr->prev->content) > (int)*((int*)ptr->content))
		{
			count++;
			index = i + 1;
		}
		if (count > 1)
			break;
		if (ptr == head)
			break;
		ptr = ptr->next;
		i++;
	}
	if (count > 1)
		return (0);
	return (index);
}

static int		is_over_median(t_dlist *head, int median)
{
	t_dlist		*ptr;

	head->prev->next = NULL;
	ptr = head;
	while (ptr)
	{
		if ((int)*((int*)ptr->content) < median)
		{
			head->prev->next = head;
			return (0);
		}
		ptr = ptr->next;
	}
	head->prev->next = head;
	return (1);
}

static void		rec_exec_instruct(char *name, t_list **inst, t_stacks *stacks)
{
	void	(*fptr)(t_stacks*);

	fptr = is_instruction(name);
	record_instruction(name, inst, fptr);
	fptr(stacks);
}

void	sort_stacks(t_stacks *stacks, t_list **inst, int median)
{
	int			i;
	int			rotate;
	char		*rotation_type;

	i = 0;
	rotate = 0;
	rotation_type = "ra";

	while (!is_over_median(stacks->head_a, median))
	{
		if (!stacks->head_b && (rotate = check_rotation(stacks->head_a)))
		{
			if (rotate > (int)stacks->a_size / 2)
			{
				rotation_type = "rra";
				rotate = (int)stacks->a_size - rotate;
			}
			while (rotate)
			{
				rec_exec_instruct(rotation_type, inst, stacks);
				rotate--;
			}
			break;
		}
		if ((int)*((int*)stacks->head_a->content) < median)
			rec_exec_instruct("pb", inst, stacks);
		else
			rec_exec_instruct("ra", inst, stacks);
		i++;
	}
}
