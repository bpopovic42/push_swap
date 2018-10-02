/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 16:19:25 by bopopovi          #+#    #+#             */
/*   Updated: 2018/10/02 19:19:36 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*static int		is_over_median(t_dlist *head, int median)
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
}*/

static void		rec_exec_instruct(char *name, t_list **inst, t_stacks *stacks)
{
	void	(*fptr)(t_stacks*);

	fptr = is_instruction(name);
	record_instruction(name, inst, fptr);
	fptr(stacks);
}

static void		rec_exec_instruct_n(char *name, t_list **inst, t_stacks *stacks, int n)
{
	void	(*fptr)(t_stacks*);

	while (n)
	{
		fptr = is_instruction(name);
		record_instruction(name, inst, fptr);
		fptr(stacks);
		n--;
	}
}


/*static int		get_highest(t_dlist *head, int *highest)
{
	t_dlist		*ptr;

	if (head)
	{
		ptr = head->next;
		if (head && head->prev)
			head->prev->next = NULL;
		*highest = *((int*)head->content);
		while (ptr)
		{
			if (*highest < *((int*)ptr->content))
				*highest = *((int*)ptr->content);
			ptr = ptr->next;
		}
		if (head && head->prev)
			head->prev->next = head;
	}
}*/

static int		get_highest_pos(t_dlist *head)
{
	t_dlist *ptr;
	int tmp;
	int i;
	int pos;

	head->prev->next = NULL;
	ptr = head;
	tmp = *((int*)head->content);
	i = 0;
	pos = 0;
	while (ptr)
	{
		if (*((int*)ptr->content) > tmp)
		{
			pos = i;
			tmp = *((int*)ptr->content);
		}
		i++;
		ptr = ptr->next;
	}
	head->prev->next = head;
	return (pos);
}

static void		push_b_highest(t_stacks *stacks, t_list **inst)
{
	int rot;
	int pos;
	int list_size;

	rot = 0;
	list_size = get_list_len(stacks->head_b);
	pos = get_highest_pos(stacks->head_b);
	if (pos > (list_size / 2))
		rec_exec_instruct_n("rrb", inst, stacks, list_size - pos);
	else
		rec_exec_instruct_n("rb", inst, stacks, pos);
	rec_exec_instruct("pa", inst, stacks);
	if (pos > (list_size / 2))
		rec_exec_instruct_n("rb", inst, stacks, list_size - pos);
	else
		rec_exec_instruct_n("rrb", inst, stacks, pos);
}

static void		print_stack(t_dlist *head)
{
	t_dlist *ptr;

	if (head)
	{
		ptr = head;
		head->prev->next = NULL;
		while (ptr)
		{
			ft_putnbr(*((int*)ptr->content));
			ft_putchar(' ');
			ptr = ptr->next;
		}
		head->prev->next = head;
	}
	else
		ft_putstr("NULL");
	ft_putchar('\n');
}

static int		quicksort_b(t_list **inst, t_stacks *stacks, int n)
{
	int i;
	int top;

	i = 0;
	top = 0;
	if (n <= 1)
		return (0);
	while (stacks->head_b)
		push_b_highest(stacks, inst);
	return (0);
}

static int		quicksort(t_list **inst, t_stacks *stacks, int n)
{
	int i = 0;
	int median;
	int top;

	i = 0;
	median = get_median(stacks->head_a);
	top = 0;
	if (n <= 1)
		return (0);
	while (i < n)
	{
		if (top >= (n / 2))
			break ;
		if (*((int*)stacks->head_a->content) < median)
		{
			rec_exec_instruct("pb", inst, stacks);
			if (*((int*)stacks->head_a->content) > *((int*)stacks->head_a->next->content))
				rec_exec_instruct("sa", inst, stacks);
			if (*((int*)stacks->head_b->content) < *((int*)stacks->head_b->next->content))
				rec_exec_instruct("sb", inst, stacks);
			top++;
		}
		else if (i < (n - 1))
			rec_exec_instruct("ra", inst, stacks);
		i++;
	}
	quicksort(inst, stacks, get_list_len(stacks->head_a));
	quicksort_b(inst, stacks, get_list_len(stacks->head_b));
	return (0);
}

void	sort_stacks(t_stacks *stacks, t_list **inst)
{
	quicksort(inst, stacks, get_list_len(stacks->head_a));
	rec_exec_instruct("pa", inst, stacks);
}
