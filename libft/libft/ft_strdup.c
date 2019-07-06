/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 12:56:09 by akorol            #+#    #+#             */
/*   Updated: 2018/11/19 17:22:27 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		len;
	char	*str2;
	char	*box;

	box = (char *)s1;
	len = ft_strlen(box) + 1;
	str2 = (char *)malloc(sizeof(char) * len);
	if (str2 == NULL)
		return (NULL);
	return (ft_memcpy(str2, s1, len));
}
