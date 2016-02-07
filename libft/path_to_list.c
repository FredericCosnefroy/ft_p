/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_to_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosnefr <fcosnefr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/02 21:00:46 by fcosnefr          #+#    #+#             */
/*   Updated: 2015/02/26 17:42:03 by fcosnefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	modify_list(t_list **list, char *str)
{
	if (ft_strequ(str, ".."))
		*list = list_remove(list);
	else
	{
		if (!ft_strequ(str, "."))
			list_add(list, str, ft_strlen(str));
	}
}

t_list	*path_to_list(char *str, char separator)
{
	t_list	*list;
	char	*s;
	int		skip;
	int		i;

	i = 0;
	skip = 0;
	list = NULL;
	if (!(s = ft_strdup(str)))
		return (list);
	while (s[i])
	{
		if (s[i] == separator)
		{
			s[i] = '\0';
			modify_list(&list, s + skip);
			skip = i + 1;
		}
		i++;
	}
	if (str[i - 1] != separator)
		modify_list(&list, s + skip);
	free(s);
	return (list);
}
