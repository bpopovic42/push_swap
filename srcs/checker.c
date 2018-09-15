/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 18:21:26 by bopopovi          #+#    #+#             */
/*   Updated: 2018/09/16 01:15:56 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include "checker.h"

/*
** Adjust argv in order to skip program name and potential command line options
*/

static int		get_av_offset(t_flags *flags)
{
	int		offset;

	offset = 1;
	offset += flags->visualizer ? 1 : 0;
	offset += flags->color ? 1 : 0;
	return (offset);
}

/*
** Check argc validity depending on the existence of command line options
*/

static int	check_argc(int ac, char **av)
{
	if (ac < 2)
		put_error("Invalid argument count");
	else if (ac > 1 && (!ft_strcmp(av[1], "-v") || !ft_strcmp(av[1], "-c")))
	{
		if (ac < 3)
			put_error("Invalid argument count");
		if (ac > 2 && ((!ft_strcmp(av[2], "-v") || !ft_strcmp(av[2], "-c"))))
		{
			if (!ft_strcmp(av[1], av[2]))
				put_error("Same argument option used twice");
			if (ac < 4)
				put_error("Invalid argument count");
		}
	}
	return (0);
}

/*
** Set command line options flags from argv
*/

static void		get_options(int ac, char **av, t_flags *flags)
{
	if (ac > 2)
	{
		flags->visualizer = (!(ft_strcmp(av[1], "-v")) || !(ft_strcmp(av[2], "-v")));
		flags->color = (!ft_strcmp(av[1], "-c") || !ft_strcmp(av[2], "-c"));
	}
	else if (ac == 2)
	{
		flags->visualizer = (!ft_strcmp(av[1], "-v"));
		flags->color = (!ft_strcmp(av[1], "-c"));
	}
}

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
	int		av_offset;

	head_a = NULL;
	head_b = NULL;
	if ((check_argc(ac, av)) < 0)
		put_error("Invalid arguments");
	else
	{
		get_options(ac, av, &flags);
		av_offset = get_av_offset(&flags);
		if (!(head_a = init_stack(ac - av_offset, av + av_offset)))
			put_error("Failed to initialize stack");
		//instructions = get_instructions();
		//execute_instructions(head_a, head_b, instructions, &flags);
		//check_if_sorted(head_a, head_b);
		print_stack(head_a);
		del_stack(&head_a);
		//if (head_b); del_stack(&head_b);
	}
	return (0);
}
