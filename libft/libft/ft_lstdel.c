/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 15:07:22 by akorol            #+#    #+#             */
/*   Updated: 2018/11/23 15:55:55 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*node;

	if (alst != NULL && del != NULL)
	{
		node = *alst;
		if (node->next != NULL)
			ft_lstdel(&(node->next), del);
		del(node->content, node->content_size);
		free(node);
	}
	*alst = NULL;
}
