/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaglio <jsaglio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 10:41:23 by jsaglio           #+#    #+#             */
/*   Updated: 2015/04/01 19:02:12 by fcosnefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 64

typedef struct		s_mem
{
	int				fd_mem;
	char			*data;
}					t_mem;

int					get_next_line(int const fd, char **line);

#endif
