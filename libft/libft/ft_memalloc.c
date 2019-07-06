/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 14:47:24 by akorol            #+#    #+#             */
/*   Updated: 2018/11/22 16:03:55 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*area;
	char	*temp;

	area = (char *)malloc(size);
	if (area == NULL)
		return (NULL);
	temp = ft_memset(area, 0, size);
	return ((void *)temp);
}
