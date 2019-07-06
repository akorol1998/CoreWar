/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memccpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 11:11:24 by akorol            #+#    #+#             */
/*   Updated: 2018/11/23 16:44:43 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *restrict dst,
		const void *restrict src, int c, size_t n)
{
	unsigned char	*dest;
	unsigned char	*source;
	size_t			i;

	i = -1;
	source = (unsigned char *)src;
	dest = (unsigned char *)dst;
	if (source == dest || n == 0)
		return (NULL);
	while (++i < n)
	{
		dest[i] = source[i];
		if (dest[i] == (unsigned char)c)
			return (dest + i + 1);
	}
	return (NULL);
}
