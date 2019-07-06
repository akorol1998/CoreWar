/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 17:46:45 by akorol            #+#    #+#             */
/*   Updated: 2019/01/15 18:31:14 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		i;
	char		*new;
	size_t		j;
	size_t		a;
	size_t		b;

	if (s1 == NULL || s2 == NULL)
		return (0);
	a = ft_strlen(s1);
	b = ft_strlen(s2);
	if (!(new = ft_strnew(a + b)))
		return (NULL);
	i = -1;
	j = -1;
	while (++i < a)
		new[i] = s1[i];
	while (++j < b)
		new[j + i] = s2[j];
	return (new);
}
