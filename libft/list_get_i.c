/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_get_i.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosnefr <fcosnefr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/05 20:32:12 by fcosnefr          #+#    #+#             */
/*   Updated: 2015/02/05 20:35:14 by fcosnefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*list_get_i(t_list *list, int index)
{
	int		i;

	if (index >= list_count(list))
		return (NULL);
	i = 0;
	while (i < index)
	{
		list = list->next;
		i++;
	}
	return (list);
}
