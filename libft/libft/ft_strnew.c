/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 15:09:35 by akorol            #+#    #+#             */
/*   Updated: 2019/01/13 18:15:27 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;
	size_t	i;

	i = -1;
	str = (char *)malloc(size + 1);
	if (str == NULL)
		return (NULL);
	while (++i < size)
		str[i] = 0;
	str[i] = '\0';
	return (str);
}
