/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 18:21:26 by bopopovi          #+#    #+#             */
/*   Updated: 2018/09/23 20:11:36 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/*
** Frees given structures, print error message if not NULL and return -1
*/

static int		clean_exit(char *msg, t_stacks *stacks, t_list **inst)
{
	free_structures(stacks, inst);
	return (put_error(msg, -1));
}

/*
** Get program input into stack a, check for potential command line options
** Then gets instructions from stdin or from stdin specified file
** Proceeds to execute given instructions
** Finally checks if input was correctly sorted and frees all allocated memory
** Returns -1 in case of error, 0 otherwise
*/

int		main(int ac, char **av)
{
	t_stacks	stacks;
	t_flags		flags;
	t_list		*instructions;
	int			options;

	instructions = NULL;
	init_stacks_container(&stacks);
	options = 1;
	if (ac > 1)
	{
		options += get_flags(ac, av, &flags);
		if (get_input(ac - options, av + options, &(stacks.head_a)) < 0)
			return (clean_exit("Bad input", &stacks, &instructions));
		if (get_instructions(&instructions) < 0)
			return (clean_exit("Bad instruction", &stacks, &instructions));
		execute_instructions(&stacks, &instructions, &flags);
		check_if_sorted(&stacks);
		free_structures(&stacks, &instructions);
	}
	else
		put_error("No arguments provided", -1);
	return (0);
}
