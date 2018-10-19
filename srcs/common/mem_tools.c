/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 22:48:35 by bopopovi          #+#    #+#             */
/*   Updated: 2018/10/19 18:11:13 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	del_stks(t_stacks *stks)
{
	if (stks->a && stks->a->prev)
		stks->a->prev->next = NULL;
	ft_dlstdel(&(stks->a), ft_bzero);
	if (stks->b && stks->b->prev)
		stks->b->prev->next = NULL;
	ft_dlstdel(&(stks->b), ft_bzero);
}

/*
** Null initializes stks's containing structure
*/

void	init_stacks_container(t_stacks *container)
{
	container->a = NULL;
	container->b = NULL;
}

void	del_instruction(void *inst, size_t size)
{
	ft_bzero((((t_inst*)inst)->name), ft_strlen(((t_inst*)inst)->name));
	ft_strdel(&(((t_inst*)inst)->name));
	ft_bzero(inst, size);
	free(inst);
}

/*
** Frees stks from container and instructions list
*/

void	free_structures(t_stacks *stks, t_list **inst)
{
	ft_lstdel(inst, &del_instruction);
	del_stks(stks);
}
