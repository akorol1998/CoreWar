/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 12:09:13 by akorol            #+#    #+#             */
/*   Updated: 2019/01/15 16:19:09 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char const		*next(char const *fmt)
{
	char		*new;

	new = ft_strchr(fmt, '%');
	return (new);
}

char			*mod_itoa(long long value, t_nigga **nig)
{
	int			i;
	long long	copy;
	char		*str;

	if (value < -9223372036854775807)
		return (ft_strdup("9223372036854775808"));
	(*nig)->sign = value < 0 ? '-' : '+';
	if ((*nig)->sign == '-')
		value *= -1;
	copy = value;
	i = 1;
	while ((copy /= 10) != 0)
		i++;
	str = ft_strnew(i);
	while (i--)
	{
		str[i] = (value % 10) + 48;
		value /= 10;
	}
	return (str);
}

char			*ft_itoa_base(uintmax_t value, int base)
{
	int			i;
	uintmax_t	n;
	char		*nbr;

	i = 1;
	n = value;
	while ((n /= base) != 0)
		i++;
	nbr = (char*)malloc(sizeof(nbr) * i);
	nbr[i] = '\0';
	while (i-- > 0)
	{
		n = '0';
		if (value % base > 9)
			n = 'a' - 10;
		nbr[i] = (value % base) + n;
		value = value / base;
	}
	return (nbr);
}
