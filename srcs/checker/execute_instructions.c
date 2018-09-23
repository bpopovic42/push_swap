/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_instructions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 19:05:19 by bopopovi          #+#    #+#             */
/*   Updated: 2018/09/23 18:33:56 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "libft.h"

int		execute_instructions(t_stacks *stacks, t_list **inst, t_flags *flags)
{
	(void)flags;
	t_list	*ptr;
	ptr = *inst;
	while (ptr)
	{
		(((t_inst*)ptr->content)->function(stacks));
		if (flags->visualizer)
			display(stacks, ((t_inst*)ptr->content)->name, flags->color);
		ptr = ptr->next;
	}
	return (0);
}
