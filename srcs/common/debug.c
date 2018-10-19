/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 22:58:28 by bopopovi          #+#    #+#             */
/*   Updated: 2018/10/19 18:10:38 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"
#include "ft_printf.h"

void	print_link_state(t_dlist *link)
{
	if (link)
	{
		if (link->prev)
			ft_printf("prev = %d, ", (int)*((int*)link->prev->content));
		else
			ft_putstr("prev = NULL, ");
		ft_printf("current = %d, ", (int)*((int*)link->content));
		if (link->next)
			ft_printf("next = %d\n", (int)*((int*)link->next->content));
		else
			ft_putstr("next = NULL\n");
	}
}

void	print_stack(t_dlist *head)
{
	t_dlist *ptr;

	if (head)
	{
		ptr = head;
		head->prev->next = NULL;
		while (ptr)
		{
			ft_putnbr_fd(*((int*)ptr->content), 2);
			ft_putchar_fd(' ', 2);
			ptr = ptr->next;
		}
		head->prev->next = head;
	}
	else
		ft_putstr_fd("NULL", 2);
	ft_putchar_fd('\n', 2);
}
