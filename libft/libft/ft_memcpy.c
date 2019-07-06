/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 14:51:42 by akorol            #+#    #+#             */
/*   Updated: 2018/11/22 16:06:53 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	const char	*sourc;
	char		*dest;
	size_t		i;

	i = -1;
	dest = (char *)dst;
	sourc = (char *)src;
	while (++i < n)
		dest[i] = sourc[i];
	return (dest);
}
