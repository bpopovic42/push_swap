/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_instructions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 19:05:19 by bopopovi          #+#    #+#             */
/*   Updated: 2018/09/22 10:56:58 by bopopovi         ###   ########.fr       */
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
		if (flags->visualizer)
		{
			ft_putstr((char*)((t_inst*)ptr->content)->name);
			ft_putchar('\n');
		}
		((void)((t_inst*)ptr->content)->function(stacks));
		if (flags->visualizer)
		{
			print_stack(stacks->head_a, 'A');
			print_stack(stacks->head_b, 'B');
		}
		ptr = ptr->next;
	}
	return (0);
}
