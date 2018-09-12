/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 18:21:26 by bopopovi          #+#    #+#             */
/*   Updated: 2018/09/12 18:53:09 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include "checker.h"

int		main(int ac, char **av)
{
	t_stack	*head;

	if (!(head = malloc(sizeof(t_stack))))
		return (-1);
	head->next = 0;
	head->prev = 0;
	head->val = 0;
	if (ac < 2)
		return (-1);
	else
	{
		if (init_stack_from_file(ac - 1, av + 1, head) < 0)
		{
			if (init_stack(av[1], head) < 0)
				return (-1);
		}
	}
	return (0);
}
