/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 11:42:00 by akorol            #+#    #+#             */
/*   Updated: 2018/11/25 13:29:38 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	char	*str;
	int		len;

	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	i = -1;
	while (s[len - 1] == ' ' || s[len - 1] == '\t' || s[len - 1] == '\n')
		len--;
	while (s[++i] == ' ' || s[i] == '\t' || s[i] == '\n')
		len--;
	if (len < 0)
		len = 0;
	if (!(str = ft_strnew(len)))
		return (NULL);
	s += i;
	i = -1;
	while (++i < len)
		str[i] = *s++;
	return (str);
}
