/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 16:29:34 by akorol            #+#    #+#             */
/*   Updated: 2019/01/13 14:50:00 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strchr(const char *s, int c)
{
	char	*arrow;

	arrow = (char *)s;
	while (*arrow != c)
	{
		if (*arrow == '\0')
			return (NULL);
		arrow++;
	}
	return (arrow);
}
