/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 01:24:44 by bopopovi          #+#    #+#             */
/*   Updated: 2018/10/19 18:11:50 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

static void		free_params(char **params)
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

static int		clean_exit(char *msg, char **params)
{
	free_params(params);
	return (put_error(msg, -1));
}

int				does_contains_digits(char *str)
{
	int		i;

	i = 0;
	if (str)
	{
		while (str[i])
		{
			if (ft_isdigit(str[i]))
				return (1);
			i++;
		}
	}
	return (0);
}

/*
** Format av parameters into a single string
** Then splits resulting string in output
** Returns -1 in case of error, 0 otherwise
*/

static int		av_to_params(int ac, char **av, char ***output)
{
	char	*join;
	char	*tmp;

	tmp = NULL;
	join = NULL;
	while (ac--)
	{
		if (!(tmp = ft_strjoin(join, *av++)))
			return (-1);
		ft_strdel(&join);
		if (!(join = ft_strjoin(tmp, " ")))
			return (-1);
		ft_strdel(&tmp);
	}
	if (!join || !(*output = ft_strsplit(join, ' ')))
		return (-1);
	if (!does_contains_digits(join))
	{
		ft_strdel(&join);
		return (-1);
	}
	ft_strdel(&join);
	return (0);
}

/*
** Skips program's name and eventual command line options from av
** Then gets formatted input from av to params, into a if valid
** Finally frees params
** Returns -1 in case of error, 0 otherwise
*/

int				get_input(int ac, char **av, t_dlist **a)
{
	char	**params;

	params = NULL;
	if (ac > 0)
	{
		if (av_to_params(ac, av, &params) < 0)
			return (clean_exit(NULL, params));
		if ((params_to_stack(params, a)) < 0)
			return (clean_exit(NULL, params));
		free_params(params);
	}
	return (0);
}
