/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 23:04:18 by bopopovi          #+#    #+#             */
/*   Updated: 2018/09/21 13:26:06 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "checker.h"
#include <limits.h>

/*
** Check if str only contains digits, signs and/or spaces
** Returns 1 if so, 0 otherwise
*/

static int		is_only_digit(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

/*
** Assign value to ptr if it is valid
*/

t_dlist		*get_next_val_if_valid(char *value)
{
	long		nbr;
	t_dlist		*tmp;

	nbr = 0;
	tmp = NULL;
	if (!check_characters(value))
		return (NULL);
	while (*value && !ft_isdigit(*value) && !ft_issign(*value))
		value++;
	if (ft_issign(*value))
		value++;
	if (*value && is_only_digit(value))
		nbr = ft_atol(value);
	else
		return (NULL);
	if (nbr > INT_MAX || nbr < INT_MIN)
		return (NULL);
	else
		tmp = ft_dlstnew(&nbr, sizeof(int));
	return (tmp);
}

/*
** Check if str only contains digits, signs and/or spaces
** Returns 1 if so, 0 otherwise
*/

int			check_characters(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && !ft_isdigit(str[i]) && !(ft_issign(str[i]) && i == 0))
			return (0);
		i++;
	}
	return (1);
}
