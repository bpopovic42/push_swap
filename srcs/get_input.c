/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 01:24:44 by bopopovi          #+#    #+#             */
/*   Updated: 2018/09/21 13:10:56 by bopopovi         ###   ########.fr       */
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
		return (-1);
	else if (ac > 1 && (!ft_strcmp(av[1], "-v") || !ft_strcmp(av[1], "-c")))
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

static int		format_av(int ac, char **av, char ***output)
{
	char	*join;
	char	*tmp;
	int		i;

	tmp = NULL;
	join = NULL;
	i = 0;
	while (i < ac)
	{
		tmp = ft_strjoin(join, av[i]);
		ft_strdel(&join);
		join = tmp;
		tmp = ft_strjoin(join, " ");
		ft_strdel(&join);
		join = tmp;
		i++;
	}
	*output = ft_strsplit(join, ' ');
	ft_strdel(&join);
	return (0);
}

static void			free_params(char **params)
{
	int		i;

	i = 0;
	while (params[i])
	{
		ft_strdel(&params[i]);
		i++;
	}
	free(params);
}

/*
** Skips program's name and eventual command line options from av
** Then gets formatted input from av to params, into head_a if valid
** Finally frees params
** Returns -1 in case of error, 0 otherwise
*/

int			get_input(int ac, char **av, t_dlist **head_a, t_flags *flags)
{
	int		av_offset;
	char	**params;

	params = NULL;
	if ((check_argc(ac, av)) < 0)
		return (-1);
	get_options(ac, av, flags);
	av_offset = get_av_offset(flags);
	format_av(ac - av_offset, av + av_offset, &params);
	if ((init_stack(params, head_a)) < 0)
		return (-1);
	free_params(params);
	return (0);
}
