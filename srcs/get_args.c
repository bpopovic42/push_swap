/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 16:49:18 by bopopovi          #+#    #+#             */
/*   Updated: 2018/09/12 18:53:59 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "checker.h"
#include "get_next_line.h"

int			init_stack(char *params, t_stack *head)
{
	t_stack	*ptr;
	int		i;

	ptr = head;
	i = 0;
	while (params[i])
	{
		if (ft_isdigit(params[i]))
		{
			ptr->next = malloc(sizeof(t_stack) * 1);
			ptr = ptr->next;
			ptr->next = 0;
			ptr->val = ft_atoi(params + i);
			while (ft_isdigit(params[i]) && params[i])
				i++;
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
	if ((init_stack(params, head)))
		return (-1);
	return (fd);
}
