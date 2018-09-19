/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 23:08:19 by bopopovi          #+#    #+#             */
/*   Updated: 2018/09/19 21:43:58 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "libft.h"

/*
** Prints value of each link in the stack until its end
*/

void		print_stack(t_dlist *head)
{
	t_dlist		*stack;
	int			count;

	stack = head;
	count = 0;
	while (stack)
	{
		ft_putnbr((*((int*)stack->content)));
		ft_putchar('\n');
		stack = stack->next;
		count++;
	}
	ft_putstr("Stack size = ");
	ft_putnbr(count);
}
