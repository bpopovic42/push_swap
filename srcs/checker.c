/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 18:21:26 by bopopovi          #+#    #+#             */
/*   Updated: 2018/09/17 16:46:33 by bopopovi         ###   ########.fr       */
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

static void		free_structures(t_stack **a, t_stack **b, t_list **inst)
{
	ft_lstdel(inst, del_lst_content);
	del_stack(a);
	del_stack(b);
}

static int		clean_exit(char *msg, t_stack **a, t_stack **b, t_list **inst)
{
	free_structures(a, b, inst);
	return (put_error(msg, -1));
}

/*
** Parse program input in order to initialize 1st stack and command line options
** Prints resulting stack if no issue was encountered
** Then frees the stack before terminating
*/

int		main(int ac, char **av)
{
	t_stack	*head_a;
	t_stack	*head_b;
	t_flags	flags;
	t_list	*instructions;

	head_a = NULL;
	head_b = NULL;
	instructions = NULL;
	if (get_input(ac, av, &head_a, &flags) < 0)
		return(clean_exit("Bad input", &head_a, &head_b, &instructions));
	if (get_instructions(&instructions) < 0)
		return(clean_exit("Bad instruction", &head_a, &head_b, &instructions));
	//execute_instructions(head_a, head_b, instructions, &flags);
	//check_if_sorted(head_a, head_b);
	//print_instructions(&instructions);
	free_structures(&head_a, &head_b, &instructions);
	return (0);
}
