/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraydel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosnefr <fcosnefr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/22 15:28:39 by fcosnefr          #+#    #+#             */
/*   Updated: 2015/02/22 15:53:39 by fcosnefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_arraydel(char ***array)
{
	size_t		i;

	if (!array || !(*array))
		return ;
	i = 0;
	while ((*array)[i])
		ft_strdel(*array + i++);
	free(*array);
	*array = NULL;
}
