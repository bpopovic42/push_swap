/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 23:08:19 by bopopovi          #+#    #+#             */
/*   Updated: 2018/10/18 18:43:38 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "ft_printf.h"

/*
** Print content of a given stack
*/

static void		display_stack(t_dlist *head)
{
	t_dlist		*stack;

	if (head)
	{
		stack = head;
		while (stack)
		{
			ft_printf(" %d", get_val(stack));
			stack = stack->next;
			if (stack == head)
				break ;
		}
	}
	else
		ft_putstr(" (null)");
}

/*
** Prints instruction and value and resulting stks state
*/

void			display(t_stacks *stks, char *instruction, int color)
{
	t_dlist		*ptr;
	int			i;

	ptr = stks->a;
	i = 0;
	if (color)
		ft_printf("{cyan}");
	ft_printf("%s :\n", instruction);
	while (i < 2)
	{
		if (color)
			ft_printf("{yellow}");
		ft_printf("STACK %c =", (ptr == stks->a ? 'A' : 'B'));
		if (color)
			ft_printf("{green}");
		display_stack(ptr);
		ft_putchar('\n');
		if (color)
			ft_printf("{eoc}");
		ptr = stks->b;
		i++;
	}
	ft_putchar('\n');
}
