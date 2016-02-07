/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosnefr <fcosnefr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 17:06:18 by fcosnefr          #+#    #+#             */
/*   Updated: 2015/03/06 19:15:37 by fcosnefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\v');
}

static int			first_non_space_char(const char *str)
{
	size_t	i;

	i = 0;
	while (is_space(str[i]) || str[i] == '\r' || str[i] == '\f')
		i++;
	return (i);
}

static long int		ft_atoi_rec(long int n, const char *str)
{
	if (*str < '0' || *str > '9')
		return (n);
	return (ft_atoi_rec(10 * n + *str - '0', str + 1));
}

long int			ft_atoli(const char *str)
{
	if (!str)
		return (0);
	str += first_non_space_char(str);
	if (*str == '-')
		return (-ft_atoi_rec(0, str + 1));
	if (*str == '+')
		return (ft_atoi_rec(0, str + 1));
	return (ft_atoi_rec(0, str));
}
