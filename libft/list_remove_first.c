/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_remove_first.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosnefr <fcosnefr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/02 21:07:02 by fcosnefr          #+#    #+#             */
/*   Updated: 2015/02/26 17:40:53 by fcosnefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*list_remove_first(t_list **list)
{
	t_list *tmp;

	if (*list != NULL)
	{
		tmp = (*list)->next;
		free(*list);
		return (tmp);
	}
	return (NULL);
}
