/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_d_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 16:42:28 by akorol            #+#    #+#             */
/*   Updated: 2019/03/18 16:43:23 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		conversion_d(t_nigga **nig, va_list args)
{
	char	*digits;
	char	*buf;
	char	*transfer;
	int		g;
	int		len;

	digits = open_d_conversion(nig, args);
	g = find_greater((*nig)->m_s, (*nig)->p_s);
	len = ft_strlen(digits);
	if (g > len)
		transfer = condition_a(g, len, digits, nig);
	else
		transfer = condition_b(digits, nig);
	if ((*nig)->out)
	{
		buf = (*nig)->out;
		(*nig)->out = ft_strjoin((*nig)->out, transfer);
		free(buf);
	}
	else
		(*nig)->out = ft_strdup(transfer);
	free(transfer);
	free(digits);
}

char		*open_d_conversion(t_nigga **nig, va_list args)
{
	char	*buf;

	if ((*nig)->width == 'l')
		buf = mod_itoa(va_arg(args, long), nig);
	else if ((*nig)->width == 'L')
		buf = mod_itoa(va_arg(args, long long), nig);
	else if ((*nig)->width == 'h')
		buf = mod_itoa((short)va_arg(args, int), nig);
	else if ((*nig)->width == 'H')
		buf = mod_itoa((signed char)va_arg(args, int), nig);
	else
		buf = mod_itoa(va_arg(args, int), nig);
	return (buf);
}

void		push(char *dest, char *src)
{
	int		i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
}

void		minus_flag_2(char *dest, int *len, int *i)
{
	while (dest[*i])
	{
		if (dest[*i] == ' ')
			*len += 1;
		*i += 1;
	}
}

void		minus_flag(char *str, t_nigga **nig)
{
	char	*dest;
	int		len;
	int		i;
	int		j;
	int		f;

	i = 0;
	len = 0;
	f = 0;
	dest = str;
	minus_flag_2(dest, &len, &i);
	j = -1;
	if ((*nig)->sign == '+' && (*nig)->blank &&
		!(*nig)->plus && *(*nig)->conv != 'o')
		f = 1;
	while (++j < i)
	{
		if (dest[j] != ' ')
		{
			dest[j - len + f] = dest[j];
			if (j - len + f != j)
				dest[j] = ' ';
		}
	}
}
