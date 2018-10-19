/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_inst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 19:05:19 by bopopovi          #+#    #+#             */
/*   Updated: 2018/10/19 18:19:42 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "libft.h"

void	exec_inst(t_stacks *stks, t_list **inst, t_flags *flags)
{
	t_list	*ptr;

	ptr = *inst;
	while (ptr)
	{
		(((t_inst*)ptr->content)->function(stks));
		if (flags->visualizer)
			display(stks, ((t_inst*)ptr->content)->name, flags->color);
		ptr = ptr->next;
	}
}
