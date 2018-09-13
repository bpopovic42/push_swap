/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 16:49:18 by bopopovi          #+#    #+#             */
/*   Updated: 2018/09/13 18:40:25 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "checker.h"
#include "get_next_line.h"
#include "limits.h"

int			*init_stack(t_stack *head, int ac, char **av)
{
	t_stack	*ptr;
	long	nbr;
	int		i;

	ptr = head;
	i = 0;
	nbr = 0;
	while (i < ac)
	{
		if (ft_isdigit(*av[i]) || ft_issign(*av[i]))
		{
			nbr = ft_atol(av[i]);
			if (nbr > INT_MAX || nbr < INT_MIN)
				put_error("Integer value is off INT limits");
			if (i)
			{
				if (!(ptr->next = stack_new((int)nbr)))
					put_error("New link creation failed");
				ptr = ptr->next;
			}
			else
				ptr->val = (int)nbr;
		}
		else
			put_error("Invalid integer parameter");
		i++;
	}
	return (0);
}

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

void			put_error(char *msg)
{
	if (msg)
		ft_putstr(msg);
	exit(-1);
}
