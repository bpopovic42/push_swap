/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 19:44:53 by bopopovi          #+#    #+#             */
/*   Updated: 2018/10/18 21:41:32 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

int		get_val(t_dlist *head)
{
	return (*((int*)head->content));
}

int		is_greater(t_dlist *a, t_dlist *b)
{
	return (get_val(a) > get_val(b));
}

int		is_smaller(t_dlist *a, t_dlist *b)
{
	return (get_val(a) < get_val(b));
}

int		is_equal(t_dlist *a, t_dlist *b)
{
	return (get_val(a) == get_val(b));
}
