/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 18:21:26 by bopopovi          #+#    #+#             */
/*   Updated: 2018/09/12 21:14:27 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include "checker.h"

int		main(int ac, char **av)
{
	t_stack	*head;

	if (!(head = stack_new(0)))
		return (-1);
	if (ac < 2)
		return (-1);
	else
	{
		if (init_stack_from_file(ac - 1, av + 1, head) < 0)
		{
			if (init_stack(av + 1, head) < 0)
				return (-1);
		}
		print_stack(head);
		del_stack(&head);
	}
	return (0);
}
