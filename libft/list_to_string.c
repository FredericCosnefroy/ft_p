/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_to_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosnefr <fcosnefr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/02 18:34:27 by fcosnefr          #+#    #+#             */
/*   Updated: 2015/02/26 17:42:56 by fcosnefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int		count_len(t_list *list, int elems)
{
	t_list	*tmp;
	int		len;
	int		i;

	i = 0;
	len = 0;
	tmp = list;
	while (i < elems)
	{
		len += ft_strlen((char *)tmp->content);
		tmp = tmp->next;
		i++;
	}
	return (len + (elems >= 2 ? elems - 1 : 0));
}

char			*list_to_string(t_list *list, char *separator)
{
	char	*str;
	int		elems;
	int		len;
	int		i;

	i = 0;
	elems = list_count(list);
	len = count_len(list, elems);
	if (!(str = ft_strnew(len)))
		return (NULL);
	while (list)
	{
		str = ft_strcat(str, list->content);
		if (elems >= 2 && i != elems - 1 && *separator != '\0')
			str = ft_strcat(str, separator);
		list = list->next;
		i++;
	}
	return (str);
}
