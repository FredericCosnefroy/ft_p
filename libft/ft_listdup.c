/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosnefr <fcosnefr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/22 15:19:06 by fcosnefr          #+#    #+#             */
/*   Updated: 2015/02/22 15:20:40 by fcosnefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_listdup(t_list *list)
{
	t_list	*tmp;
	t_list	*dup;

	tmp = list;
	dup = NULL;
	while (tmp)
	{
		dup = list_add(&dup, tmp->content, tmp->content_size);
		tmp = tmp->next;
	}
	return (dup);
}
