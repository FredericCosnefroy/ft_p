/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosnefr <fcosnefr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/02 17:57:53 by fcosnefr          #+#    #+#             */
/*   Updated: 2015/02/18 11:34:18 by fcosnefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*list_add(t_list **list, void const *content, size_t content_size)
{
	t_list	*tmp;

	tmp = *list;
	if (!tmp)
		return ((*list) = ft_lstnew(content, content_size));
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = ft_lstnew(content, content_size);
	}
	return (*list);
}
