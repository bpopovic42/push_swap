/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 18:21:26 by bopopovi          #+#    #+#             */
/*   Updated: 2018/10/19 18:24:26 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/*
** Frees given structures, print error message if not NULL and return -1
*/

static int		clean_exit(char *msg, t_stacks *stks, t_list **inst)
{
	free_structures(stks, inst);
	return (put_error(msg, -1));
}

/*
** Get program input into stack a, check for potential command line options
** Then gets instructions from stdin or from stdin specified file
** Proceeds to execute given instructions
** Finally checks if input was correctly sorted and frees all allocated memory
** Returns -1 in case of error, 0 otherwise
*/

int				main(int ac, char **av)
{
	t_stacks	stks;
	t_flags		flags;
	t_list		*instructions;
	int			options;

	instructions = NULL;
	init_stacks_container(&stks);
	options = 1;
	if (ac > 1)
	{
		options += get_flags(ac, av, &flags);
		if (get_input(ac - options, av + options, &(stks.a)) < 0)
			return (clean_exit("Bad input", &stks, &instructions));
		if (get_instructions(&instructions) < 0)
			return (clean_exit("Bad instruction", &stks, &instructions));
		exec_inst(&stks, &instructions, &flags);
		if (is_sorted(stks.a, 1) && !stks.b)
			ft_putendl("OK");
		else
			ft_putendl("KO");
		free_structures(&stks, &instructions);
	}
	return (0);
}
