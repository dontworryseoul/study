/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jso <jso@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 11:21:24 by jso               #+#    #+#             */
/*   Updated: 2021/01/14 11:21:51 by jso              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*newstart;
	t_list	*newnext;

	if (!f || !lst)
		return (NULL);
	new = ft_lstnew(f(lst->content));
	if (!new)
		return (NULL);
	lst = lst->next;
	newstart = new;
	while (lst)
	{
		newnext = ft_lstnew(f(lst->content));
		if (!newnext)
		{
			ft_lstclear(&newstart, del);
			return (0);
		}
		new->next = newnext;
		new = newnext;
		lst = lst->next;
	}
	return (newstart);
}
