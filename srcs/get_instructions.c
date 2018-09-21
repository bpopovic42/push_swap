/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_instructions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 23:02:57 by bopopovi          #+#    #+#             */
/*   Updated: 2018/09/21 13:10:58 by bopopovi         ###   ########.fr       */
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

static void		record_instruction(t_list **instructions, int val)
{
	t_list	*new;
	t_list	*ptr;

	new = NULL;
	ptr = NULL;
	if (!(new = ft_lstnew(&val, sizeof(val))))
		exit(-1);
	if (!(*instructions))
		*instructions = new;
	else
	{
		ptr = *instructions;
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = new;
	}
}

static int		exit_clean(char *msg, char **line)
{
	ft_strdel(line);
	return (put_error(msg, -1));
}

int				get_instructions(t_list **instructions)
{
	char	*line;
	int		ret;
	int		val;
	int		fd;

	line = NULL;
	ret = 0;
	val = 0;
	fd = 0;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		val = is_instruction(line);
		if (!val && (*instructions || (fd = open(line, O_RDONLY)) < 0))
			return (exit_clean("Wrong filename or instruction", &line));
		record_instruction(instructions, val);
		ft_strdel(&line);
	}
	if (fd > 0)
		close(fd);
	ft_strdel(&line);
	return (ret);
}
