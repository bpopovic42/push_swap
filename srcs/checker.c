/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 18:21:26 by bopopovi          #+#    #+#             */
/*   Updated: 2018/09/19 04:18:22 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include "checker.h"

static void		del_lst_content(void *ptr, size_t size)
{
	(void)size;
	free(ptr);
}

static void		free_structures(t_ptr *stacks, t_list **inst)
{
	ft_lstdel(inst, del_lst_content);
	del_stack(&(stacks->head_a));
	del_stack(&(stacks->head_b));
}

static int		clean_exit(char *msg, t_ptr *stacks, t_list **inst)
{
	free_structures(stacks, inst);
	return (put_error(msg, -1));
}

/*
** Parse program input in order to initialize 1st stack and command line options
** Prints resulting stack if no issue was encountered
** Then frees the stack before terminating
*/

int		main(int ac, char **av)
{
	t_ptr	ptr;
	t_flags	flags;
	t_list	*instructions;

	ptr.head_a = NULL;
	ptr.head_b = NULL;
	ptr.tail_a = NULL;
	ptr.tail_b = NULL;
	instructions = NULL;
	if (get_input(ac, av, &(ptr.head_a), &flags) < 0)
		return (clean_exit("Bad input", &ptr, &instructions));
	if (get_instructions(&instructions) < 0)
		return (clean_exit("Bad instruction", &ptr, &instructions));
	execute_instructions(&ptr, &instructions, &flags);
	//check_if_sorted(head_a, head_b);
	//print_instructions(&instructions);
	free_structures(&ptr, &instructions);
	return (0);
}
