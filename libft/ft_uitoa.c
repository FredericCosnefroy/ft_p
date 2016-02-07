/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosnefr <fcosnefr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 13:14:56 by fcosnefr          #+#    #+#             */
/*   Updated: 2015/01/18 16:52:48 by fcosnefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static size_t	ft_intlen(unsigned int n)
{
	unsigned int i;

	if (n == 0)
		return (1);
	i = 0;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char			*ft_uitoa(unsigned int n)
{
	char			*str;
	unsigned int	len;
	int				memlen;

	len = ft_intlen(n);
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	memlen = len;
	while (len > 0)
	{
		str[len-- - 1] = (n % 10) + '0';
		n /= 10;
	}
	str[memlen] = '\0';
	return (str);
}
