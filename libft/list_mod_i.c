/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_mod_i.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosnefr <fcosnefr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 13:23:15 by fcosnefr          #+#    #+#             */
/*   Updated: 2015/02/26 17:39:56 by fcosnefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*list_mod_i(t_list **list, void *content, size_t content_size, int in)
{
	t_list	*tmp;
	int		i;

	if (!(*list))
		return (*list);
	tmp = *list;
	i = 0;
	in = (in < 0 ? 0 : in);
	while (tmp)
	{
		if (i == in)
		{
			free(tmp->content);
			tmp->content = content;
			tmp->content_size = content_size;
			return (*list);
		}
		tmp = tmp->next;
		i++;
	}
	return (*list);
}
