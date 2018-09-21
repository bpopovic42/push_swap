/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_instructions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 23:02:57 by bopopovi          #+#    #+#             */
/*   Updated: 2018/09/21 21:35:48 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "checker.h"
#include "libft.h"

static void		(*is_instruction(char *instruction))(t_stacks*)
{
	if (!ft_strcmp("sa", instruction))
		return (&swap_a);
	else if (!ft_strcmp("sb", instruction))
		return (&swap_b);
	else if (!ft_strcmp("ss", instruction))
		return (&swap_ab);
	else if (!ft_strcmp("pa", instruction))
		return (&push_a);
	else if (!ft_strcmp("pb", instruction))
		return (&push_b);
	else if (!ft_strcmp("ra", instruction))
		return (&rotate_a);
	else if (!ft_strcmp("rb", instruction))
		return (&rotate_b);
	else if (!ft_strcmp("rr", instruction))
		return (&rotate_ab);
	else if (!ft_strcmp("rra", instruction))
		return (&reverse_rotate_a);
	else if (!ft_strcmp("rrb", instruction))
		return (&reverse_rotate_b);
	else if (!ft_strcmp("rrr", instruction))
		return (&reverse_rotate_ab);
	return (NULL);
}


static void		record_instruction(char *name, t_list **inst, void (*val)(t_stacks*))
{
	t_list	*new;
	t_list	*ptr;
	t_inst	*tmp;

	new = NULL;
	ptr = NULL;
	tmp = NULL;
	tmp = malloc(sizeof(*tmp));
	tmp->name = NULL;
	if (!(tmp->name = ft_strdup(name)))
		exit(-1);
	//if (!(tmp->function = ft_memdup(val, sizeof(val))))
//		exit(-1);
	tmp->function = val;
	if (!(new = ft_lstnew(0, 0)))
		exit(-1);
	new->content = tmp;
	if (!(*inst))
		*inst = new;
	else
	{
		ptr = *inst;
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = new;
	}
}

void			del_instruction(void *inst, size_t size)
{
	(void)size;
	ft_bzero((((t_inst*)inst)->name), ft_strlen(((t_inst*)inst)->name));
	ft_strdel(&(((t_inst*)inst)->name));
	free(inst);
}

static int		exit_clean(char *msg, t_list **inst, char **line)
{
	ft_strdel(line);
	ft_lstdel(inst, del_instruction);
	return (put_error(msg, -1));
}

int				get_instructions(t_list **inst)
{
	char	*line;
	int		ret;
	void	(*val)(t_stacks*);
	int		fd;

	line = NULL;
	ret = 0;
	val = NULL;
	fd = 0;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		val = is_instruction(line);
		if (!val && (*inst || (fd = open(line, O_RDONLY)) < 0))
			return (exit_clean("Wrong filename or instruction", inst, &line));
		if (val)
			record_instruction(line, inst, val);
		ft_strdel(&line);
	}
	if (fd > 0)
		close(fd);
	ft_strdel(&line);
	return (ret);
}
