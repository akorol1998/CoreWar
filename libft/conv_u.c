/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 14:15:22 by akorol            #+#    #+#             */
/*   Updated: 2019/03/19 14:16:01 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*open_u_conversion(t_nigga **nig, va_list args)
{
	char		*buf;

	if ((*nig)->width == 'l')
		buf = ft_itoa_base(va_arg(args, unsigned long), 10);
	else if ((*nig)->width == 'L')
	{
		buf = ft_itoa_base(va_arg(args, unsigned long long), 10);
	}
	else if ((*nig)->width == 'h')
		buf = ft_itoa_base((unsigned short)va_arg(args, int), 10);
	else if ((*nig)->width == 'H')
		buf = ft_itoa_base((unsigned char)va_arg(args, int), 10);
	else
		buf = ft_itoa_base(va_arg(args, unsigned), 10);
	return (buf);
}

char			*cond_part_1(t_nigga **nig)
{
	char		*temp;

	temp = ft_strnew((*nig)->p_s);
	fill2(temp, (*nig)->p_s);
	fill_wz_zero(temp);
	return (temp);
}

char			*cond_part_2(t_nigga **nig)
{
	char		*temp;

	temp = ft_strnew((*nig)->m_s);
	fill2(temp, (*nig)->m_s);
	fill_wz_zero(temp);
	return (temp);
}

char			*cond_b(char *digits, t_nigga **nig)
{
	char		*temp;

	if ((*nig)->hash && *(*nig)->conv == 'o')
		temp = ft_strjoin("0", digits);
	else
		temp = ft_strdup(digits);
	return (temp);
}

void			check_weather_o(char *digits, char **temp, t_nigga **nig)
{
	if ((*nig)->hash && *(*nig)->conv == 'o')
		(*temp) = ft_strjoin("0", digits);
	else
		(*temp) = ft_strdup(digits);
}
