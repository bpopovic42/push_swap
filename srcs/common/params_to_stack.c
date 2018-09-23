/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params_to_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 23:06:40 by bopopovi          #+#    #+#             */
/*   Updated: 2018/09/23 22:33:59 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"
#include <limits.h>

/*
** Check if str only contains digits
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
** Check if str only contains digits, signs and/or spaces
** Returns 1 if so, 0 otherwise
*/

static int			check_string_validity(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && !ft_isdigit(str[i]) && !ft_issign(str[i]) && !i)
			return (0);
		i++;
	}
	return (1);
}

/*
** Assign atoi converted value to ptr if it is valid
*/

static t_dlist		*strict_atoi(char *value)
{
	long		nbr;
	t_dlist		*tmp;

	nbr = 0;
	tmp = NULL;
	if (!check_string_validity(value))
		return (NULL);
	while (*value && *value == ' ')
		value++;
	if (is_only_digit(value) || (ft_issign(*value) && is_only_digit(value + 1)))
	{
		if (*value)
			nbr = ft_atol(value);
		else
			return (NULL);
	}
	else
		return (NULL);
	if (nbr > INT_MAX || nbr < INT_MIN)
		return (NULL);
	tmp = ft_dlstnew(&nbr, sizeof(int));
	return (tmp);
}

/*
** Checks the list for duplicated values
** Returns 1 if duplicates have been found, 0 otherwise
*/

static int		check_duplicates(t_dlist *list)
{
	t_dlist		*ptr;
	int			current;

	while (list)
	{
		ptr = list->next;
		current = *((int*)list->content);
		while (ptr)
		{
			if (*((int*)ptr->content) == current)
				return (1);
			ptr = ptr->next;
		}
		list = list->next;
	}
	return (0);
}

/*
** Initialize 1st stack by parsing program arguments
*/

int			params_to_stack(char **params, t_dlist **head)
{
	t_dlist	*tmp;
	int		i;

	i = 0;
	while (params[i])
	{
		if (!(tmp = strict_atoi(params[i])))
			return (-1);
		ft_dlstadd(head, tmp);
		i++;
	}
	if (check_duplicates(*head))
		return (-1);
	tmp->next = *head;
	(*head)->prev = tmp;
	return (0);
}
