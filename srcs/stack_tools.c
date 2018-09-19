/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 23:06:40 by bopopovi          #+#    #+#             */
/*   Updated: 2018/09/20 00:41:30 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "libft.h"

/*
** Initialize 1st stack by parsing program arguments
*/

int			init_stack(char **params, t_dlist **head, t_dlist **tail)
{
	t_dlist	*ptr;
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
		else
			*tail = ptr;
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

t_dlist			*stack_new(int val)
{
	t_dlist		*stack;

	stack = 0;
	if (!(stack = malloc(sizeof(t_dlist))))
		exit(-1);
	stack->prev = 0;
	stack->next = 0;
	stack->content = ft_memdup(&val, sizeof(int));
	stack->content_size = sizeof(int);
	return (stack);
}

/*
** Erase and free all stack's links until its end
*/

void			del_stack(t_dlist **stack)
{
	t_dlist		*head;
	t_dlist		*ptr;

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

void			delone_stack(t_dlist **stack)
{
	t_dlist		*ptr;

	ptr = *stack;
	ptr->prev = 0;
	ptr->next = 0;
	ft_bzero(ptr->content, ptr->content_size);
	ptr->content_size = 0;
	free(ptr->content);
	free(ptr);
}
