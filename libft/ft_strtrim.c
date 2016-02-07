/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosnefr <fcosnefr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 15:56:31 by fcosnefr          #+#    #+#             */
/*   Updated: 2014/11/10 15:56:34 by fcosnefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	return (c == '\t' || c == ' ' || c == '\n');
}

static int	ft_getstart(char const *s)
{
	unsigned int i;

	i = 0;
	while (s[i] && ft_isspace(s[i]))
		i++;
	return (i);
}

char		*ft_strtrim(char const *s)
{
	unsigned int	start;
	unsigned int	i;
	size_t			len;
	size_t			s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	start = ft_getstart(s);
	i = 0;
	while ((i < s_len) && (ft_isspace(s[s_len - i - 1])))
		i++;
	len = (i + start > s_len) ? 0 : s_len - i - start;
	return (ft_strsub(s, start, len));
}
