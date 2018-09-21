/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 23:06:40 by bopopovi          #+#    #+#             */
/*   Updated: 2018/09/20 23:22:37 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "libft.h"

/*
** Initialize 1st stack by parsing program arguments
*/

int			init_stack(char **params, t_dlist **head, t_dlist **tail)
{
	t_dlist	*ptr;
	int		i;
	int		tmp;

	tmp = 0;
	if (!(*head = ft_dlstnew(&tmp, sizeof(int))))
		exit(-1);
	ptr = *head;
	i = 0;
	while (params[i])
	{
		if (params[i + 1])
		{
			if (!(ptr->next = ft_dlstnew(&tmp, sizeof(int))))
				exit(-1);
			ptr->next->prev = ptr;
		}
		else
			*tail = ptr;
		if ((get_next_val_if_valid(ptr, params[i])) < 0)
			return (-1);
		i++;
		ptr = ptr->next;
	}
	return (0);
}
