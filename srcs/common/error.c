/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 23:09:16 by bopopovi          #+#    #+#             */
/*   Updated: 2018/09/23 20:10:43 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

/*
** Prints msg and exit with code -1
*/

int				put_error(char *msg, int return_value)
{
	if (msg)
	{
		if (PRINT_ERROR_MSG)
			ft_putendl(msg);
		else
			ft_putendl("Error");
	}
	return (return_value);
}
