/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rec_inst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 17:17:17 by bopopovi          #+#    #+#             */
/*   Updated: 2018/10/19 18:27:47 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	update_stks_sizes(t_stacks *stks, char *instruction)
{
	if (!ft_strcmp("pa", instruction))
	{
		stks->a_size++;
		stks->b_size--;
	}
	if (!ft_strcmp("pb", instruction))
	{
		stks->b_size++;
		stks->a_size--;
	}
}

void		exec_instruct(char *name, t_list **inst, t_stacks *stks)
{
	void	(*fptr)(t_stacks*);

	update_stks_sizes(stks, name);
	fptr = is_instruction(name);
	rec_inst(name, inst, fptr);
	fptr(stks);
	if (PRINT_ERROR_MSG)
	{
		ft_putendl_fd(name, 2);
		print_stack(stks->a);
		print_stack(stks->b);
		ft_putchar_fd('\n', 2);
	}
}

void		exec_instruct_n(char *name, t_list **inst, t_stacks *stks, int n)
{
	void	(*fptr)(t_stacks*);

	while (n)
	{
		update_stks_sizes(stks, name);
		fptr = is_instruction(name);
		rec_inst(name, inst, fptr);
		fptr(stks);
		if (PRINT_ERROR_MSG)
		{
			ft_putendl_fd(name, 2);
			print_stack(stks->a);
			print_stack(stks->b);
			ft_putchar_fd('\n', 2);
		}
		n--;
	}
}
