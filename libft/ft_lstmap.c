/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qarcher <qarcher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/30 15:41:12 by qarcher           #+#    #+#             */
/*   Updated: 2015/01/22 13:01:09 by qarcher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_list_push_back(t_list **begin_list, t_list *list)
{
	t_list		*tmp;

	tmp = *begin_list;
	if (tmp == NULL)
		*begin_list = ft_lstnew(list->content, list->content_size);
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = ft_lstnew(list->content, list->content_size);
	}
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*list;

	list = NULL;
	if (lst && f)
	{
		while (lst)
		{
			ft_list_push_back(&list, f(lst));
			lst = lst->next;
		}
		return (list);
	}
	return (NULL);
}
