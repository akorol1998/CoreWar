/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 17:02:14 by akorol            #+#    #+#             */
/*   Updated: 2019/01/14 16:01:08 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*baton;

	if (s == NULL)
		return (NULL);
	if (!(baton = ft_strnew(len)))
		return (NULL);
	return (ft_strncpy(baton, s + start, len));
}
