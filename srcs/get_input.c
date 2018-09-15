/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 01:24:44 by bopopovi          #+#    #+#             */
/*   Updated: 2018/09/16 01:47:00 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "libft.h"

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
** Adjust argv in order to skip program name and potential command line options
*/

static int		get_av_offset(t_flags *flags)
{
	int		offset;

	offset = 1;
	if (flags)
	{
		offset += flags->visualizer ? 1 : 0;
		offset += flags->color ? 1 : 0;
	}
	return (offset);
}

/*
** Set command line options flags from argv
*/

static void		get_options(int ac, char **av, t_flags *flags)
{
	if (flags)
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
}

/*
** Compute argument offset skipping program's name
** Also skips eventual command line options if *flags is not NULL
** Then get formated input from av into head_a if valid
*/

int			get_input(int ac, char **av, t_stack **head_a, t_flags *flags)
{
	int		av_offset;

	if ((check_argc(ac, av)) < 0)
		put_error("Invalid arguments");
	get_options(ac, av, flags);
	av_offset = get_av_offset(flags);
	if (!(*head_a = init_stack(ac - av_offset, av + av_offset)))
		put_error("Failed to initialize stack");
	return (0);
}
