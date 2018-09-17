/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_instructions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 23:02:57 by bopopovi          #+#    #+#             */
/*   Updated: 2018/09/17 02:37:21 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "checker.h"
#include "libft.h"

static int		is_instruction(char *instruction)
{
	if (!ft_strcmp("sa", instruction))
		return (1);
	else if (!ft_strcmp("sb", instruction))
		return (2);
	else if (!ft_strcmp("ss", instruction))
		return (3);
	else if (!ft_strcmp("pa", instruction))
		return (4);
	else if (!ft_strcmp("pb", instruction))
		return (5);
	else if (!ft_strcmp("ra", instruction))
		return (6);
	else if (!ft_strcmp("rb", instruction))
		return (7);
	else if (!ft_strcmp("rr", instruction))
		return (8);
	else if (!ft_strcmp("rra", instruction))
		return (9);
	else if (!ft_strcmp("rrb", instruction))
		return (10);
	else if (!ft_strcmp("rrr", instruction))
		return (11);
	return (0);
}

static int		record_instruction(t_list **instructions, int val)
{
	t_list	*ptr;

	ptr = NULL;
	if (!(ptr = ft_lstnew(&val, sizeof(val))))
		return (-1);
	if (!(*instructions))
		*instructions = ptr;
	else
		(*instructions)->next = ptr;
	return (0);
}

int				get_instructions(t_list **instructions)
{
	t_list	*ptr;
	char	*line;
	int		ret;
	int		val;
	int		fd;

	ptr = NULL;
	line = NULL;
	ret = 0;
	val = 0;
	fd = 0;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (!(val = is_instruction(line)))
		{
			if (ptr || ((fd = open(line, O_RDONLY)) < 0))
				return (-1);
		}
		else
		{
			record_instruction(&ptr, val);
			if (!(*instructions))
				*instructions = ptr;
			else
				ptr = ptr->next;
		}
		ft_strdel(&line);
	}
	ft_strdel(&line);
	return (ret);
}
