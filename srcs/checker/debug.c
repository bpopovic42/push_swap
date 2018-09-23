/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 22:58:28 by bopopovi          #+#    #+#             */
/*   Updated: 2018/09/21 22:59:20 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "libft.h"
#include "ft_printf.h"

void	print_link_state(t_dlist *link)
{
	if (link)
	{
		if (link->prev)
			ft_printf("prev = %d, ", (int)*((int*)link->prev->content));
		else
			ft_putstr("prev = NULL, ");
		ft_printf("current = %d, ",(int)*((int*)link->content));
		if (link->next)
			ft_printf("next = %d\n", (int)*((int*)link->next->content));
		else
			ft_putstr("next = NULL\n");
	}
}
