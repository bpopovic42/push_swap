/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 23:04:18 by bopopovi          #+#    #+#             */
/*   Updated: 2018/09/15 23:38:42 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "checker.h"
#include <limits.h>

/*
** Assign value to ptr if it is valid
*/

int			get_next_val_if_valid(t_stack *ptr, char *value)
{
	long	nbr;

	nbr = 0;
	if (ft_isdigit(*value) || (ft_issign(*value) && ft_isdigit(*(value + 1))))
	{
		if (!is_only_digits(value))
			put_error("Invalid integer parameter");
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
** Check if str is a correctly formated number representation
** Returns 1 if so, 0 otherwise
*/

int			is_only_digits(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && !(ft_issign(str[i]) && i == 0))
			return (0);
		i++;
	}
	return (1);
}
