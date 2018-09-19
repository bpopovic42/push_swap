/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 23:06:40 by bopopovi          #+#    #+#             */
/*   Updated: 2018/09/19 03:52:47 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "libft.h"

/*
** Initialize 1st stack by parsing program arguments
*/

int			init_stack(char **params, t_stack **head)
{
	t_stack	*ptr;
	int		i;

	if (!(*head = stack_new(0)))
		exit(-1);
	ptr = *head;
	i = 0;
	while (params[i])
	{
		if (params[i + 1])
		{
			if (!(ptr->next = stack_new(0)))
				exit(-1);
			ptr->next->prev = ptr;
		}
		if ((get_next_val_if_valid(ptr, params[i])) < 0)
			return (-1);
		i++;
		ptr = ptr->next;
	}
	return (0);
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
		exit(-1);
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
