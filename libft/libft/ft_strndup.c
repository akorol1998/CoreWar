/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 10:51:10 by akorol            #+#    #+#             */
/*   Updated: 2019/07/22 10:56:59 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strndup(char *s1, int n)
{
	int		len;
	char	*box;

	len = ft_strlen(s1);
	if (n < len)
		len = n;
	if (!(box = ft_strnew(len)))
		return (NULL);
	return (ft_memcpy(box, s1, len));
}
