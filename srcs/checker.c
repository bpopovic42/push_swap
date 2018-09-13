/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 18:21:26 by bopopovi          #+#    #+#             */
/*   Updated: 2018/09/13 17:06:43 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include "checker.h"

int		main(int ac, char **av)
{
	t_stack	*head;
	char	**nbrs;
	int		fd;

	fd = 0;
	nbrs = 0;
	if (ac < 2)
		return (-1);
	else
	{
		if (!(head = init_stack(ac - 1, av + 1)))
			return (-1);
		print_stack(head);
		del_stack(&head);
	}
	return (0);
}
