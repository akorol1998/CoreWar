/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 16:03:58 by akorol            #+#    #+#             */
/*   Updated: 2018/11/19 16:27:18 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*node;
	t_list	*start;

	if (!lst)
		return (NULL);
	node = f(lst);
	start = node;
	while (lst->next)
	{
		lst = lst->next;
		node->next = f(lst);
		if (!node)
			return (NULL);
		node = node->next;
	}
	return (start);
}
