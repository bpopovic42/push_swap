/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 18:21:26 by bopopovi          #+#    #+#             */
/*   Updated: 2018/09/10 18:46:04 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include "libft/includes/get_next_line.h"
#include <fcntl.h>
#include <unistd.h>

int		main(void)
{
	char *line;
	int fd;
	int size;

	line = NULL;
	fd = 0;
	size = 1;
	if ((fd = open("test.txt", O_RDONLY) <= 0))
		return (-1);
	while (size)
	{
		ft_putchar('x');
		size = get_next_line(fd, &line);
		ft_putstr(line);
		ft_strdel(&line);
	}
	close(fd);
	return (0);
}
