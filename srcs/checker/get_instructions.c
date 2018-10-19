/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_instructions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 23:02:57 by bopopovi          #+#    #+#             */
/*   Updated: 2018/10/19 18:24:44 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void		local_free(char **line, int fd)
{
	if (fd > 0)
		close(fd);
	if (line)
		ft_strdel(line);
}

static int		local_exit(char *msg, char **line, int fd)
{
	local_free(line, fd);
	return (put_error(msg, -1));
}

int				get_instructions(t_list **inst)
{
	char	*line;
	int		ret;
	void	(*fptr)(t_stacks*);
	int		fd;

	line = NULL;
	ret = 0;
	fptr = NULL;
	fd = 0;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		fptr = is_instruction(line);
		if (!fptr && (*inst || (fd = open(line, O_RDONLY)) < 0))
			return (local_exit(NULL, &line, fd));
		else if (fptr)
			rec_inst(line, inst, fptr);
		ft_strdel(&line);
	}
	local_free(&line, fd);
	return (ret);
}
