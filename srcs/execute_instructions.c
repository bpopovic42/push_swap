/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_instructions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 19:05:19 by bopopovi          #+#    #+#             */
/*   Updated: 2018/09/21 21:48:16 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "libft.h"

int		execute_instructions(t_stacks *stacks, t_list **inst, t_flags *flags)
{
	(void)stacks;
	(void)inst;
	(void)flags;
	t_list	*ptr;
	ptr = *inst;
	while (ptr)
	{
		ft_putstr((char*)((t_inst*)ptr->content)->name);
		ft_putchar('\n');
		((void)((t_inst*)ptr->content)->function(stacks));
		print_stack(stacks->head_a, 'A');
		print_stack(stacks->head_b, 'B');
		ptr = ptr->next;
	}
	return (0);
}
