/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 22:48:35 by bopopovi          #+#    #+#             */
/*   Updated: 2018/09/23 20:05:11 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	del_stacks(t_stacks *stacks)
{
	if (stacks->head_a && stacks->head_a->prev)
		stacks->head_a->prev->next = NULL;
	ft_dlstdel(&(stacks->head_a), ft_bzero);
	if (stacks->head_b && stacks->head_b->prev)
		stacks->head_b->prev->next = NULL;
	ft_dlstdel(&(stacks->head_b), ft_bzero);
}

/*
** Null initializes stacks's containing structure
*/

void			init_stacks_container(t_stacks *container)
{
	container->head_a = NULL;
	container->head_b = NULL;
}

void			del_instruction(void *inst, size_t size)
{
	ft_bzero((((t_inst*)inst)->name), ft_strlen(((t_inst*)inst)->name));
	ft_strdel(&(((t_inst*)inst)->name));
	ft_bzero(inst, size);
	free(inst);
}

/*
** Frees stacks from container and instructions list
*/

void			free_structures(t_stacks *stacks, t_list **inst)
{
	ft_lstdel(inst, &del_instruction);
	del_stacks(stacks);
}
