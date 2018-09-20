/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 18:21:26 by bopopovi          #+#    #+#             */
/*   Updated: 2018/09/20 15:19:56 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include "checker.h"

/*
** Frees stacks from container and instructions list
*/

static void		free_structures(t_stacks *stacks, t_list **inst)
{
	ft_lstdel(inst, ft_bzero);
	ft_dlstdel(&(stacks->head_a), ft_bzero);
	ft_dlstdel(&(stacks->head_b), ft_bzero);
}

/*
** Frees given structures, print error message if option is set and return -1
*/

static int		clean_exit(char *msg, t_stacks *stacks, t_list **inst)
{
	free_structures(stacks, inst);
	return (put_error(msg, -1));
}

/*
** Null initializes stacks's containing structure
*/

static void		init_stacks_container(t_stacks *container)
{
	container->head_a = NULL;
	container->head_b = NULL;
	container->tail_a = NULL;
	container->tail_b = NULL;
}

/*
** Get program input into stack a, check for potential command line options
** Then gets instructions from stdin or from stdin specified file
** Proceeds to execute given instructions
** Finally checks if input was correctly sorted and frees all allocated memory
** Returns -1 in case of error, 0 otherwise
*/

int		main(int ac, char **av)
{
	t_stacks	stacks;
	t_flags		flags;
	t_list		*instructions;

	instructions = NULL;
	init_stacks_container(&stacks);
	if (get_input(ac, av, &(stacks.head_a), &(stacks.tail_a), &flags) < 0)
		return (clean_exit("Bad input", &stacks, &instructions));
	if (get_instructions(&instructions) < 0)
		return (clean_exit("Bad instruction", &stacks, &instructions));
	execute_instructions(&stacks, &instructions, &flags);
	print_stack(stacks.head_a);
	print_stack(stacks.head_b);
	while (stacks.head_a)
	{
		t_dlist *tmp = ft_dlstpop(&(stacks.head_a));
		ft_dlstpush(&(stacks.head_b), tmp);
		ft_putstr("\nA ");
		print_stack(stacks.head_a);
		ft_putstr("\nB ");
		print_stack(stacks.head_b);
	}
	//check_if_sorted(head_a, head_b);
	//print_instructions(&instructions);
	free_structures(&stacks, &instructions);
	return (0);
}
