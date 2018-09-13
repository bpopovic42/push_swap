/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 18:21:26 by bopopovi          #+#    #+#             */
/*   Updated: 2018/09/13 18:39:05 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include "checker.h"

int		main(int ac, char **av)
{
	t_stack	*head;

	if (!(head = stack_new(0)))
		put_error("Failed to allocate stack head");
	if (ac < 2)
		put_error("Invalid argument count");
	else
	{
		if ((init_stack(head, ac - 1, av + 1)) < 0)
			put_error("Failed to initialize stack");
		print_stack(head);
		del_stack(&head);
	}
	return (0);
}
