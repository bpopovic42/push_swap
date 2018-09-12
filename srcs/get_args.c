/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 16:49:18 by bopopovi          #+#    #+#             */
/*   Updated: 2018/09/12 21:14:15 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "checker.h"
#include "get_next_line.h"

int			init_stack(char **av, t_stack *head)
{
	t_stack	*ptr;
	int		i;

	ptr = head;
	i = 0;
	while (av[i])
	{
		if (ft_isdigit(*av[i]))
		{
			if (!(ptr->next = stack_new(ft_atoi(av[i]))))
				return (-1);
			ptr = ptr->next;
		}
		i++;
	}
	return (0);
}

int			init_stack_from_file(int ac, char **av, t_stack *head)
{
	char	*params;
	int		size;
	int		fd;

	params = 0;
	size = 1;
	fd = 0;
	(void)ac;
	if ((fd = open(av[0], O_RDONLY)) < 0)
		return (-1);
	size = get_next_line(fd, &params);
	if ((init_stack(ft_strsplit(params, ' '), head)))
		return (-1);
	return (fd);
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
