/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 11:34:50 by akorol            #+#    #+#             */
/*   Updated: 2018/11/25 13:30:57 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dest;
	char	*sorc;
	size_t	i;

	i = -1;
	dest = (char *)dst;
	sorc = (char *)src;
	if (sorc > dest)
	{
		while (++i < len)
			dest[i] = sorc[i];
	}
	else
	{
		while (len)
		{
			dest[len - 1] = sorc[len - 1];
			len--;
		}
	}
	return (dest);
}
