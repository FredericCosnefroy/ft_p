/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist_add_first.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosnefr <fcosnefr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/07 19:33:14 by fcosnefr          #+#    #+#             */
/*   Updated: 2015/03/07 19:51:24 by fcosnefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	dlist_add_first(t_dlist **lst, const void *content,
		const unsigned int content_size)
{
	t_dlist	*node;

	if (!lst)
		return ;
	node = ft_dlstnew(content, content_size);
	if (!(*lst))
		*lst = node;
	else
	{
		node->next = *lst;
		(*lst)->prev = node;
		*lst = node;
	}
}
