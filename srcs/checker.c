/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 18:21:26 by bopopovi          #+#    #+#             */
/*   Updated: 2018/09/19 22:52:05 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include "checker.h"

/*
** Tool function passed to ft_lstdelone to properly free list link
*/

static void		del_lst_content(void *ptr, size_t size)
{
	(void)size;
	free(ptr);
}

/*
** Frees stacks from container and instructions list
*/

static void		free_structures(t_stacks *stacks, t_list **inst)
{
	ft_lstdel(inst, del_lst_content);
	del_stack(&(stacks->head_a));
	del_stack(&(stacks->head_b));
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
	if (get_input(ac, av, &(stacks.head_a), &flags) < 0)
		return (clean_exit("Bad input", &stacks, &instructions));
	if (get_instructions(&instructions) < 0)
		return (clean_exit("Bad instruction", &stacks, &instructions));
	execute_instructions(&stacks, &instructions, &flags);
	print_stack(stacks.head_a);
	//check_if_sorted(head_a, head_b);
	//print_instructions(&instructions);
	free_structures(&stacks, &instructions);
	return (0);
}
