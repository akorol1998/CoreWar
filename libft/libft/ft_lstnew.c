/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 14:00:05 by akorol            #+#    #+#             */
/*   Updated: 2018/11/23 18:42:42 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*newlink;

	if (!(newlink = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL)
	{
		newlink->content = NULL;
		newlink->content_size = 0;
	}
	else
	{
		newlink->content = malloc(content_size);
		ft_memcpy(newlink->content, content, content_size);
		newlink->content_size = content_size;
	}
	newlink->next = NULL;
	return (newlink);
}
