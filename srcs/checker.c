/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 18:21:26 by bopopovi          #+#    #+#             */
/*   Updated: 2018/09/17 02:49:03 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include "checker.h"

/*static void		print_instructions(t_list **list)
{
	t_list *ptr;

	ptr = *list;
	while (ptr)
	{
		ft_putnbr(*((int*)ptr->content));
		ft_putchar(' ');
		ptr = ptr->next;
	}
}*/

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
	get_input(ac, av, &head_a, &flags);
	if (get_instructions(&instructions) < 0)
		put_error("Bad instruction");
	//execute_instructions(head_a, head_b, instructions, &flags);
	//check_if_sorted(head_a, head_b);
	//print_stack(head_a);
	//print_instructions(&instructions);
	ft_lstdel(&instructions, ft_bzero);
	del_stack(&head_a);
	while (1);
	//if (head_b); del_stack(&head_b);
	return (0);
}
