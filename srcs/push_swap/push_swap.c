/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 22:01:37 by bopopovi          #+#    #+#             */
/*   Updated: 2018/10/19 18:16:36 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "checker.h"

/*
** Frees given structures, print error message if not NULL and return -1
*/

static int		clean_exit(char *msg, t_stacks *stks, t_list **inst)
{
	free_structures(stks, inst);
	return (put_error(msg, -1));
}

static char		*instruction_optimizer(t_list **first, t_list *second)
{
	char *a;
	char *b;

	a = (char*)((t_inst*)(*first)->content)->name;
	if (second)
	{
		b = (char*)((t_inst*)second->content)->name;
		if (!ft_strcmp(a, "sa") && !ft_strcmp(b, "sb"))
			return ("ss");
		else if (!ft_strcmp(a, "sb") && !ft_strcmp(b, "sa"))
			return ("ss");
		else if (!ft_strcmp(a, "ra") && !ft_strcmp(b, "rb"))
			return ("rr");
		else if (!ft_strcmp(a, "rb") && !ft_strcmp(b, "ra"))
			return ("rr");
		else if (!ft_strcmp(a, "rra") && !ft_strcmp(b, "rrb"))
			return ("rrr");
		else if (!ft_strcmp(a, "rrb") && !ft_strcmp(b, "rra"))
			return ("rrr");
	}
	return (NULL);
}

static void		print_instructions(t_list *inst)
{
	t_list		*ptr;
	char		*optimized;

	ptr = inst;
	while (ptr)
	{
		optimized = instruction_optimizer(&ptr, ptr->next);
		if (optimized)
		{
			ft_putendl(optimized);
			ptr = ptr->next;
		}
		else
			ft_putendl((char*)((t_inst*)ptr->content)->name);
		ptr = ptr->next;
	}
}

static int		get_stack_size(t_dlist *stack)
{
	t_dlist		*ptr;
	int			size;

	size = 0;
	ptr = stack;
	if (stack && stack->prev)
		stack->prev->next = NULL;
	while (ptr && stack)
	{
		ptr = ptr->next;
		size++;
	}
	if (stack && stack->prev)
		stack->prev->next = stack;
	return (size);
}

int				main(int ac, char **av)
{
	t_stacks	stks;
	t_list		*inst;

	inst = NULL;
	init_stacks_container(&stks);
	if (ac > 1)
	{
		if (get_input(ac - 1, av + 1, &(stks.a)) < 0)
			return (clean_exit("Bad input", &stks, &inst));
		stks.a_size = get_stack_size(stks.a);
		stks.b_size = get_stack_size(stks.b);
		if (!is_sorted(stks.a, 1))
		{
			if (!check_rotation(&inst, &stks))
			{
				sort_a(&inst, &stks);
				sort_b(&inst, &stks);
			}
		}
		print_instructions(inst);
		free_structures(&stks, &inst);
	}
	return (0);
}
