/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosnefr <fcosnefr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 13:14:56 by fcosnefr          #+#    #+#             */
/*   Updated: 2015/01/18 16:47:09 by fcosnefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static size_t	ft_intlen(int n)
{
	size_t i;

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

char			*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		memlen;
	int		bound;

	len = ft_intlen(n);
	if (n < 0)
		len++;
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	bound = 0;
	if (n < 0)
	{
		str[0] = '-';
		bound = 1;
	}
	memlen = len;
	while (len > bound)
	{
		str[len-- - 1] = ((n < 0) ? (-1 * (n % 10)) + '0' : (n % 10) + '0');
		n /= 10;
	}
	str[memlen] = '\0';
	return (str);
}
