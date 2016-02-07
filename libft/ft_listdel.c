/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listdel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosnefr <fcosnefr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/22 15:20:57 by fcosnefr          #+#    #+#             */
/*   Updated: 2015/02/22 16:19:45 by fcosnefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_listdel(t_list **list, const int free_content)
{
	while (*list)
	{
		if (free_content)
		{
			free((*list)->content);
			(*list)->content = NULL;
		}
		*list = list_remove_first(list);
	}
}
