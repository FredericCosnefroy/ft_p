/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_to_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosnefr <fcosnefr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/05 19:39:03 by fcosnefr          #+#    #+#             */
/*   Updated: 2015/02/12 20:43:26 by fcosnefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	**list_to_array(t_list *list)
{
	char	**array;
	t_list	*tmp;
	int		len;
	int		i;

	i = 0;
	tmp = list;
	len = list_count(list);
	array = (char **)malloc(sizeof(char *) * (len + 1));
	while (tmp)
	{
		array[i] = tmp->content;
		i++;
		tmp = tmp->next;
	}
	array[i] = NULL;
	return (array);
}
