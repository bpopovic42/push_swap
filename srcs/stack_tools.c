/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 23:06:40 by bopopovi          #+#    #+#             */
/*   Updated: 2018/09/21 14:00:52 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "libft.h"

/*
** Initialize 1st stack by parsing program arguments
*/

int			init_stack(char **params, t_dlist **head)
{
	t_dlist	*tmp;
	int		i;

	i = 0;
	while (params[i])
	{
		if (!(tmp = get_next_val_if_valid(params[i])))
			return (-1);
		ft_dlstadd(head, tmp);
		i++;
	}
	tmp->next = *head;
	(*head)->prev = tmp;
	return (0);
}
