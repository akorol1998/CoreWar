/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 15:49:41 by akorol            #+#    #+#             */
/*   Updated: 2018/11/25 13:27:50 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*tmp;
	int		i;

	if (s == NULL)
		return (NULL);
	tmp = ft_strnew(ft_strlen(s));
	if (!tmp)
		return (NULL);
	i = 0;
	while (s[i])
	{
		tmp[i] = f(s[i]);
		i++;
	}
	return (tmp);
}
