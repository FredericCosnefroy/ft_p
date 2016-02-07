/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_remove.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosnefr <fcosnefr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/02 18:08:28 by fcosnefr          #+#    #+#             */
/*   Updated: 2015/02/26 17:40:34 by fcosnefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*list_remove(t_list **list)
{
	t_list	*tmp;
	t_list	*ptmp;

	if (*list == NULL)
		return (NULL);
	if (!(*list)->next)
	{
		free(*list);
		return (NULL);
	}
	tmp = *list;
	ptmp = *list;
	while (tmp->next)
	{
		ptmp = tmp;
		tmp = tmp->next;
	}
	ptmp->next = NULL;
	free(tmp);
	return (*list);
}
