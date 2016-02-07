/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaglio <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 19:49:38 by jsaglio           #+#    #+#             */
/*   Updated: 2015/03/31 20:30:15 by fcosnefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

static t_mem		*get_mem(int const fd, t_list **lst_ptr)
{
	t_list	*lst;
	t_mem	mem;

	lst = *lst_ptr;
	while (lst)
	{
		if (((t_mem *)(lst->content))->fd_mem == fd)
			return (lst->content);
		lst = lst->next;
	}
	mem.fd_mem = fd;
	mem.data = ft_strnew(BUFF_SIZE);
	if (!mem.data || !(lst = ft_lstnew(&mem, sizeof(t_mem))))
	{
		free(mem.data);
		return (NULL);
	}
	ft_lstadd(lst_ptr, lst);
	return ((*lst_ptr)->content);
}

static int			read_mem(t_mem *mem, char **line)
{
	char		*cursor;
	int			res;

	res = 0;
	if ((cursor = ft_strchr(mem->data, '\n')))
	{
		*cursor = '\0';
		cursor++;
		res = 1;
	}
	if (!(*line = ft_strdup(mem->data)))
		return (-1);
	if (res)
		ft_strcpy(mem->data, cursor);
	else
		ft_strclr(mem->data);
	return (res);
}

static int			read_buf(char *buf, t_mem *mem, char **line)
{
	char		*temp;
	int			res;

	res = 0;
	if ((temp = ft_strchr(buf, '\n')))
	{
		*temp = '\0';
		temp++;
		ft_strcpy(mem->data, temp);
		res = 1;
	}
	temp = *line;
	if (!(*line = ft_strjoin(*line, buf)))
		return (-1);
	free (temp);
	return (res);
}

static int			free_str_return(char *str, int i)
{
	free(str);
	return (i);
}

int					get_next_line(int const fd, char **line)
{
	static t_list	*lst = NULL;
	t_mem			*mem;
	int				ret;
	char			*buf;

	if (!line || !(BUFF_SIZE > 0) || !(mem = get_mem(fd, &lst)))
		return (-1);
	if (!(ret = read_mem(mem, line)))
	{
		if (!(buf = ft_strnew(BUFF_SIZE)))
			return (-1);
		while ((ret = read(fd, buf, BUFF_SIZE)))
		{
			if (ret < 0)
				return (free_str_return(buf, -1));
			buf[ret] = '\0';
			if ((ret = read_buf(buf, mem, line)))
				return (free_str_return(buf, ret));
		}
		if (**line)
			return (free_str_return(buf, 1));
		return (free_str_return(buf, 0));
	}
	return (ret);
}
