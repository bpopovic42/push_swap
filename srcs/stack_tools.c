/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 23:06:40 by bopopovi          #+#    #+#             */
/*   Updated: 2018/09/16 00:51:01 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "libft.h"

/*
** Initialize 1st stack by parsing program arguments
*/

t_stack			*init_stack(int ac, char **av)
{
	t_stack	*head;
	t_stack	*ptr;
	int		i;

	if (!(head = stack_new(0)))
		put_error("Memory allocation failure");
	ptr = head;
	i = 0;
	while (i < ac)
	{
		if (i + 1 < ac)
		{
			if (!(ptr->next = stack_new(0)))
				put_error("Memory allocation failure");
			ptr->next->prev = ptr;
		}
		if ((get_next_val_if_valid(ptr, av[i])) < 0)
			return (0);
		i++;
		ptr = ptr->next;
	}
	return (head);
}

/*
** Set a newly allocated stack link to value 'val'
** Returns a pointer to the new link
*/

t_stack			*stack_new(int val)
{
	t_stack		*stack;

	stack = 0;
	if (!(stack = malloc(sizeof(t_stack))))
		return (0);
	stack->prev = 0;
	stack->next = 0;
	stack->val = val;
	return (stack);
}

/*
** Erase and free all stack's links until its end
*/

void			del_stack(t_stack **stack)
{
	t_stack		*head;
	t_stack		*ptr;

	head = *stack;
	while (head)
	{
		ptr = head->next;
		delone_stack(&head);
		head = ptr;
	}
}

/*
** Erase and frees one stack link
*/

void			delone_stack(t_stack **stack)
{
	t_stack		*ptr;

	ptr = *stack;
	ptr->prev = 0;
	ptr->next = 0;
	ptr->val = 0;
	free(ptr);
}
