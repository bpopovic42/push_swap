/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 23:04:18 by bopopovi          #+#    #+#             */
/*   Updated: 2018/09/19 04:24:12 by bopopovi         ###   ########.fr       */
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

int			get_next_val_if_valid(t_stack *ptr, char *value)
{
	long	nbr;

	nbr = 0;
	if (!check_characters(value))
		return (-1);
	while (*value && !ft_isdigit(*value) && !ft_issign(*value))
		value++;
	if (ft_issign(*value))
		value++;
	if (*value && is_only_digit(value))
		nbr = ft_atol(value);
	else
		return (-1);
	if (nbr > INT_MAX || nbr < INT_MIN)
		return (-1);
	else
		ptr->val = (int)nbr;
	return (0);
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
