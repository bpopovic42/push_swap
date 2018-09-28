/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 22:01:37 by bopopovi          #+#    #+#             */
/*   Updated: 2018/09/27 18:57:36 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "checker.h"

/*
** Frees given structures, print error message if not NULL and return -1
*/

static int		clean_exit(char *msg, t_stacks *stacks, t_list **inst)
{
	free_structures(stacks, inst);
	return (put_error(msg, -1));
}

static void		print_instructions(t_list *inst)
{
	t_list		*ptr;

	ptr = inst;
	while (ptr)
	{
		ft_putstr((char*)((t_inst*)ptr->content)->name);
		ft_putchar('\n');
		ptr = ptr->next;
	}
}

static void		get_stack_sizes(t_stacks *stacks)
{
	t_dlist		*ptr;

	if (stacks->head_a && stacks->head_a->prev)
		stacks->head_a->prev->next = NULL;
	if (stacks->head_b && stacks->head_b->prev)
		stacks->head_b->prev->next = NULL;
	stacks->a_size = 0;
	stacks->b_size = 0;
	ptr = stacks->head_a;
	while (ptr && stacks->head_a)
	{
		ptr = ptr->next;
		stacks->a_size++;
	}
	ptr = stacks->head_b;
	while (ptr && stacks->head_b)
	{
		ptr = ptr->next;
		stacks->b_size++;
	}
	if (stacks->head_a && stacks->head_a->prev)
		stacks->head_a->prev->next = stacks->head_a;
	if (stacks->head_b && stacks->head_b->prev)
		stacks->head_b->prev->next = stacks->head_b;
}

int		main(int ac, char **av)
{
	t_stacks	stacks;
	t_list		*instructions;
	int			median;

	instructions = NULL;
	init_stacks_container(&stacks);
	median = 0;
	if (ac > 1)
	{
		if (get_input(ac - 1, av + 1, &(stacks.head_a)) < 0)
			return (clean_exit("Bad input", &stacks, &instructions));
		median = get_median(&stacks);
		//ft_printf("Median = %d\n", median);
		get_stack_sizes(&stacks);
		//ft_printf("a = %d, b = %d\n", stacks.a_size, stacks.b_size);
		sort_stacks(&stacks, &instructions, median);
		print_instructions(instructions);
		free_structures(&stacks, &instructions);
	}
	return (0);
}
