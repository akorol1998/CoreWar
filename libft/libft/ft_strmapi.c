/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 16:09:10 by akorol            #+#    #+#             */
/*   Updated: 2018/11/23 18:14:47 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char				*box;
	unsigned int		i;

	i = 0;
	if (s == NULL)
		return (NULL);
	box = ft_strnew(ft_strlen(s));
	if (!box)
		return (NULL);
	while (s[i])
	{
		box[i] = f(i, s[i]);
		i++;
	}
	return (box);
}
