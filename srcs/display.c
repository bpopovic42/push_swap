/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 23:08:19 by bopopovi          #+#    #+#             */
/*   Updated: 2018/09/21 00:16:37 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "libft.h"

/*
** Prints value of each link in the stack until its end
*/

void		print_stack(t_dlist *head, char stack_name)
{
	t_dlist		*stack;
	int			count;

	stack = head;
	count = 0;
	if (head)
	{
		while (stack)
		{
			ft_putnbr((*((int*)stack->content)));
			if (stack->next)
				ft_putchar(' ');
			stack = stack->next;
			count++;
		}
	}
	else
		ft_putstr("(null)");
	ft_putchar('\n');
	ft_putchar(stack_name);
	ft_putchar(' ');
	ft_putstr("Stack size = ");
	ft_putnbr(count);
	ft_putchar('\n');
	ft_putchar('\n');
}
