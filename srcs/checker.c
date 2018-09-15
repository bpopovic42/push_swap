/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 18:21:26 by bopopovi          #+#    #+#             */
/*   Updated: 2018/09/16 01:35:01 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include "checker.h"

/*
** Parse program input in order to initialize 1st stack and command line options
** Prints resulting stack if no issue was encountered
** Then frees the stack before terminating
*/

int		main(int ac, char **av)
{
	t_stack	*head_a;
	t_stack	*head_b;
	t_flags	flags;

	head_a = NULL;
	head_b = NULL;
	get_input(ac, av, &head_a, &flags);
	//instructions = get_instructions();
	//execute_instructions(head_a, head_b, instructions, &flags);
	//check_if_sorted(head_a, head_b);
	print_stack(head_a);
	del_stack(&head_a);
	//if (head_b); del_stack(&head_b);
	return (0);
}
