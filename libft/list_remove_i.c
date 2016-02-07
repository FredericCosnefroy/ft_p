/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_remove_i.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosnefr <fcosnefr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/05 20:12:42 by fcosnefr          #+#    #+#             */
/*   Updated: 2015/02/26 17:41:35 by fcosnefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*list_remove_i(t_list **list, int n)
{
	int		i;
	t_list	*current;
	t_list	*temp_node;

	current = *list;
	temp_node = NULL;
	i = 0;
	if (n == 0)
	{
		free((*list)->content);
		*list = list_remove_first(list);
		return (*list);
	}
	while (i < n - 1)
	{
		if (!current->next)
			return (*list);
		current = current->next;
		i++;
	}
	temp_node = current->next;
	current->next = temp_node->next;
	free(temp_node->content);
	free(temp_node);
	return (*list);
}
