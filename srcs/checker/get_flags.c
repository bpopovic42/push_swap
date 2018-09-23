/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 11:07:23 by bopopovi          #+#    #+#             */
/*   Updated: 2018/09/23 11:14:33 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "libft.h"

/*
** Check argc validity depending on the existence of command line options
*/

static int	check_argc(int ac, char **av)
{
	if (ac > 1 && (!ft_strcmp(av[1], "-v") || !ft_strcmp(av[1], "-c")))
	{
		if (ac < 3)
			return (-1);
		if (ac > 2 && ((!ft_strcmp(av[2], "-v") || !ft_strcmp(av[2], "-c"))))
		{
			if (!ft_strcmp(av[1], av[2]))
				return (-1);
			if (ac < 4)
				return (-1);
		}
	}
	return (0);
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
** Adjust argv in order to skip command line options
*/

static int		get_av_offset(t_flags *flags)
{
	int		offset;

	offset = 0;
	if (flags)
	{
		offset += flags->visualizer ? 1 : 0;
		offset += flags->color ? 1 : 0;
	}
	return (offset);
}

int				get_flags(int ac, char **av, t_flags *flags)
{
	check_argc(ac, av);
	get_options(ac, av, flags);
	return (get_av_offset(flags));
}
