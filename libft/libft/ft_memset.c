/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 11:06:03 by akorol            #+#    #+#             */
/*   Updated: 2018/11/19 17:20:03 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	mychar;
	char			*box;
	size_t			i;

	box = (char *)b;
	mychar = (unsigned char)c;
	i = -1;
	while (++i < len)
		box[i] = mychar;
	return (box);
}
