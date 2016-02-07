/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosnefr <fcosnefr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 20:32:44 by fcosnefr          #+#    #+#             */
/*   Updated: 2014/11/09 16:02:12 by fcosnefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	*ft_backwardmemcpy(void *s1, const void *s2, size_t i)
{
	char	*dst;
	char	*src;

	dst = (char *)s1;
	src = (char *)s2;
	while (i > 0)
	{
		dst[i - 1] = src[i - 1];
		i--;
	}
	return (s1);
}

void			*ft_memmove(void *dst, const void *src, size_t len)
{
	if (dst == NULL || src == NULL)
		return (NULL);
	if (dst == src)
		return (dst);
	if (dst < src)
		ft_memcpy(dst, src, len);
	else
		ft_backwardmemcpy(dst, src, len);
	return (dst);
}
