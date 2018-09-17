/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 23:09:16 by bopopovi          #+#    #+#             */
/*   Updated: 2018/09/17 15:31:08 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "libft.h"

/*
** Prints msg and exit with code -1
*/

int				put_error(char *msg, int return_value)
{
	if (PRINT_ERROR_MSG)
		ft_putstr(msg);
	return (return_value);
}
