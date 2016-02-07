/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosnefr <fcosnefr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 15:40:11 by fcosnefr          #+#    #+#             */
/*   Updated: 2014/11/10 14:43:00 by fcosnefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t i;
	size_t j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = 0;
	if (s2[0] == '\0')
		return ((char *)s1);
	while (s1[i] && (i < n))
	{
		j = 0;
		while (s1[i + j] == s2[j] && s1[i + j] && s2[j] && (i + j < n))
		{
			j++;
			if (s2[j] == '\0')
				return ((char *)&s1[i + j - ft_strlen(s2)]);
			if (s1[i + j] == '\0')
				return (NULL);
		}
		i++;
	}
	return (NULL);
}
