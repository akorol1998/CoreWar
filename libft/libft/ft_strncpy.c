/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strncpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 10:51:50 by akorol            #+#    #+#             */
/*   Updated: 2019/02/12 16:44:51 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *str1, const char *str2, size_t len)
{
	size_t	i;
	size_t	j;

	j = ft_strlen(str2);
	i = 0;
	while (i < len && i < j)
	{
		if (i >= j)
			return (str1);
		else
			str1[i] = str2[i];
		i++;
	}
	return (str1);
}
