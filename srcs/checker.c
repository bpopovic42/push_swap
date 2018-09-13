/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 18:21:26 by bopopovi          #+#    #+#             */
/*   Updated: 2018/09/13 16:14:41 by bopopovi         ###   ########.fr       */
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
	if (!(head = stack_new(0)))
		return (-1);
	if (ac < 2)
		return (-1);
	else
	{
		if (ac == 2)
		{
			if ((fd = try_to_open_file(av[1])) >= 0)
				nbrs = read_nbrs_from_file(fd);
		}
		if (!nbrs)
			nbrs = av + 1;
		if (!(head = init_stack(nbrs)))
			return (-1);
		print_stack(head);
		del_stack(&head);
	}
	return (0);
}
