/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 23:08:19 by bopopovi          #+#    #+#             */
/*   Updated: 2018/09/23 18:43:13 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "ft_printf.h"

/*
** Print content of a given stack
*/

static void		print_stack(t_dlist *head)
{
	t_dlist		*stack;

	if (head)
	{
		stack = head;
		while (stack)
		{
			ft_putchar(' ');
			ft_printf("%d", (*((int*)stack->content)));
			stack = stack->next;
			if (stack == head)
				break ;
		}
	}
	else
		ft_putstr("(null)");
}

/*
** Prints instruction and value and resulting stacks state
*/

void		display(t_stacks *stacks, char *instruction, int color)
{
	t_dlist		*ptr;
	int			i;

	ptr = stacks->head_a;
	i = 0;
	if (color)
		ft_printf("{cyan}");
	ft_printf("%s :\n", instruction);
	while (i < 2)
	{
		if (color)
			ft_printf("{yellow}");
		ft_printf("STACK %c =", (ptr == stacks->head_a ? 'A' : 'B'));
		if (color)
			ft_printf("{green}");
		print_stack(ptr);
		ft_putchar('\n');
		if (color)
			ft_printf("{eoc}");
		ptr = stacks->head_b;
		i++;
	}
	ft_putchar('\n');
}
