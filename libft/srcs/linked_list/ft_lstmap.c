/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguinio <yguinio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 11:38:31 by yguinio           #+#    #+#             */
/*   Updated: 2024/11/18 09:52:49 by yguinio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlist;
	t_list	*newelt;

	if (!lst || !f || !del)
		return (NULL);
	newlist = NULL;
	while (lst)
	{
		newelt = ft_lstnew((*f)(lst->content));
		if (!newelt)
		{
			while (newlist)
			{
				newelt = newlist->next;
				(*del)(newlist->content);
				free(newlist);
				newlist = newelt;
			}
			return (NULL);
		}
		ft_lstadd_back(&newlist, newelt);
		lst = lst->next;
	}
	return (newlist);
}
