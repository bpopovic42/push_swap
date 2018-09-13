/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 16:49:18 by bopopovi          #+#    #+#             */
/*   Updated: 2018/09/13 17:07:37 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "checker.h"
#include "get_next_line.h"

t_stack			*init_stack(int ac, char **av)
{
	t_stack	*head;
	t_stack	*ptr;
	int		i;

	head = NULL;
	ptr = NULL;
	i = 0;
	while (i < ac)
	{
		if (ft_isdigit(*av[i]))
		{
			if (i == 0)
			{
				if (!(ptr = stack_new(ft_atoi(av[i]))))
					return (NULL);
				head = ptr;
			}
			else
			{
				if (!(ptr->next = stack_new(ft_atoi(av[i]))))
					return (NULL);
				ptr = ptr->next;
			}
		}
		else
			return (NULL);
		i++;
	}
	return (head);
}

void		print_stack(t_stack *head)
{
	t_stack		*stack;

	stack = head;
	while (stack)
	{
		ft_putnbr(stack->val);
		ft_putchar('\n');
		stack = stack->next;
	}
}

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

void			delone_stack(t_stack **stack)
{
	t_stack		*ptr;

	ptr = *stack;
	ptr->prev = 0;
	ptr->next = 0;
	ptr->val = 0;
	free(ptr);
}
