/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosnefr <fcosnefr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/19 15:29:23 by fcosnefr          #+#    #+#             */
/*   Updated: 2014/11/19 15:29:24 by fcosnefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_pushback(t_list *lst, t_list *n)
{
	t_list	*temp;

	if (!n)
		return (NULL);
	if (!lst)
		return (n);
	temp = lst;
	while (temp->next)
		temp = temp->next;
	temp->next = ft_lstnew(n->content, n->content_size);
	return (lst);
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elemi))
{
	t_list	*res;

	if (!lst || !f)
		return (NULL);
	res = NULL;
	while (lst)
	{
		if (!(res = ft_pushback(res,
						f(ft_lstnew(lst->content, lst->content_size)))))
			return (NULL);
		lst = lst->next;
	}
	return (res);
}
