/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_count.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosnefr <fcosnefr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/02 18:21:30 by fcosnefr          #+#    #+#             */
/*   Updated: 2015/02/02 18:28:44 by fcosnefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	list_count(t_list *list)
{
	int i;

	if (!list)
		return (0);
	i = 0;
	while (list)
	{
		list = list->next;
		i++;
	}
	return (i);
}
