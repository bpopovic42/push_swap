/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_tools.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 17:41:23 by bopopovi          #+#    #+#             */
/*   Updated: 2018/10/19 18:38:18 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	(*is_instruction(char *instruction))(t_stacks*)
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

void	rec_inst(char *name, t_list **inst, void (*val)(t_stacks*))
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
