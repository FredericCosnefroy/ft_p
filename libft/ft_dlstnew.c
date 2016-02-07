/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosnefr <fcosnefr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/19 15:27:40 by fcosnefr          #+#    #+#             */
/*   Updated: 2015/03/07 19:46:25 by fcosnefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_dlist	*ft_dlstnew(void const *content, const unsigned int content_size)
{
	t_dlist	*res;

	if (!(res = (t_dlist *)malloc(sizeof(t_dlist))))
		return (NULL);
	if (!content)
	{
		res->content = NULL;
		res->content_size = 0;
	}
	else
	{
		if (!(res->content = (void *)malloc(content_size)))
		{
			free(res);
			return (NULL);
		}
		ft_memmove(res->content, content, content_size);
		res->content_size = content_size;
	}
	res->next = NULL;
	res->next = NULL;
	return (res);
}
