/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 18:21:26 by bopopovi          #+#    #+#             */
/*   Updated: 2018/09/13 20:51:33 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include "checker.h"

static void	adjust_input(int *ac, char ***av, int options)
{
	int		offset;

	offset = 1 + options;
	*ac -= offset;
	*av += offset;
}

static int	check_argv(int ac, char **av)
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

static void		get_options(int ac, char **av, int *visualizer, int *color)
{
	if (ac > 2)
	{
		*visualizer = (!(ft_strcmp(av[1], "-v")) || !(ft_strcmp(av[2], "-v")));
		*color = (!ft_strcmp(av[1], "-c") || !ft_strcmp(av[2], "-c"));
	}
	else if (ac > 1)
	{
		*visualizer = (!ft_strcmp(av[1], "-v"));
		*color = (!ft_strcmp(av[1], "-c"));
	}
}

int		main(int ac, char **av)
{
	t_stack	*head;
	int		visualizer;
	int		color;

	head = NULL;
	visualizer = 0;
	color = 0;
	if ((check_argv(ac, av)) < 0)
		put_error("Invalid arguments");
	else
	{
		get_options(ac, av, &visualizer, &color);
		adjust_input(&ac, &av, visualizer + color);
		if (!(head = stack_new(0)))
			put_error("Failed to allocate stack head");
		if ((init_stack(head, ac, av)) < 0)
			put_error("Failed to initialize stack");
		print_stack(head);
		del_stack(&head);
	}
	return (0);
}
