/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosnefr <fcosnefr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 20:05:54 by fcosnefr          #+#    #+#             */
/*   Updated: 2014/11/05 16:00:47 by fcosnefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	stop;
	unsigned char	*dst_bytes;
	unsigned char	*src_bytes;

	stop = (unsigned char)c;
	dst_bytes = (unsigned char*)dst;
	src_bytes = (unsigned char*)src;
	i = 0;
	while (i < n)
	{
		dst_bytes[i] = src_bytes[i];
		if (src_bytes[i] == stop)
			return (dst_bytes + i + 1);
		i++;
	}
	return (NULL);
}
