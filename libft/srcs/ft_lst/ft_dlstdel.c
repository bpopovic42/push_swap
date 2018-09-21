/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstdel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 14:30:45 by bopopovi          #+#    #+#             */
/*   Updated: 2018/09/21 13:19:40 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_dlstdel(t_dlist **alst, void (*del)(void *, size_t))
{
	t_dlist		*head;
	t_dlist		*ptr;

	head = *alst;
	while (head && head->next != *alst)
	{
		ptr = head->next;
		ft_dlstdelone(&head, del);
		head = ptr;
	}
}
