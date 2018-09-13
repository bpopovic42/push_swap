/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 16:49:18 by bopopovi          #+#    #+#             */
/*   Updated: 2018/09/13 21:06:25 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "checker.h"
#include "get_next_line.h"
#include "limits.h"

/*
** Initialize 1st stack by parsing program arguments
*/

int			init_stack(t_stack *head, int ac, char **av)
{
	t_stack	*ptr;
	int		i;

	ptr = head;
	i = 0;
	while (i < ac)
	{
		if (i + 1 < ac)
		{
			ptr->next = stack_new(0);
			ptr->next->prev = ptr;
		}
		if ((get_next_val_if_valid(ptr, av[i])) < 0)
			return (-1);
		i++;
		ptr = ptr->next;
	}
	return (0);
}

/*
** Assign value to ptr if it is valid
*/

int			get_next_val_if_valid(t_stack *ptr, char *value)
{
	long	nbr;

	nbr = 0;
	if (ft_isdigit(*value) || (ft_issign(*value) && ft_isdigit(*(value + 1))))
	{
		nbr = ft_atol(value);
		if (nbr > INT_MAX || nbr < INT_MIN)
			put_error("Integer value is off INT limits");
		else
			ptr->val = (int)nbr;
	}
	else
		put_error("Invalid integer parameter");
	return (0);
}

/*
** Prints value of each link in the stack until its end
*/

void		print_stack(t_stack *head)
{
	t_stack		*stack;
	int			count;

	stack = head;
	count = 0;
	while (stack)
	{
		ft_putnbr(stack->val);
		ft_putchar('\n');
		stack = stack->next;
		count++;
	}
	ft_putstr("Stack size = ");
	ft_putnbr(count);
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

/*
** Prints msg and exit with code -1
*/

void			put_error(char *msg)
{
	if (msg)
		ft_putstr(msg);
	exit(-1);
}
