/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosnefr <fcosnefr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 17:06:18 by fcosnefr          #+#    #+#             */
/*   Updated: 2015/02/26 17:43:28 by fcosnefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\v');
}

static int	first_non_space_char(const char *str)
{
	size_t	i;

	i = 0;
	while (is_space(str[i]) || str[i] == '\r' || str[i] == '\f')
		i++;
	return (i);
}

static int	ft_atoi_rec(int n, const char *str)
{
	if (*str < '0' || *str > '9')
		return (n);
	return (ft_atoi_rec(10 * n + *str - '0', str + 1));
}

int			ft_atoi(const char *str)
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
