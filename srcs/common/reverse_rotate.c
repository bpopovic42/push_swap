/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 16:33:17 by bopopovi          #+#    #+#             */
/*   Updated: 2018/09/21 16:35:50 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "libft.h"

void		reverse_rotate_a(t_stacks *stks)
{
	if (stks->a && stks->a->prev)
		stks->a = stks->a->prev;
}

void		reverse_rotate_b(t_stacks *stks)
{
	if (stks->b && stks->b->prev)
		stks->b = stks->b->prev;
}

void		reverse_rotate_ab(t_stacks *stks)
{
	reverse_rotate_a(stks);
	reverse_rotate_b(stks);
}
