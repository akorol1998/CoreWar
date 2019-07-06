/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 14:41:32 by akorol            #+#    #+#             */
/*   Updated: 2019/02/26 14:41:34 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*hex_converter(t_nigga **nig, va_list args)
{
	char		*buf;

	if ((*nig)->width == 'l')
		buf = ft_itoa_base(va_arg(args, unsigned long), 16);
	else if ((*nig)->width == 'L')
		buf = ft_itoa_base(va_arg(args, unsigned long long), 16);
	else if ((*nig)->width == 'h')
		buf = ft_itoa_base((unsigned short)va_arg(args, int), 16);
	else if ((*nig)->width == 'H')
		buf = ft_itoa_base((unsigned char)va_arg(args, int), 16);
	else
		buf = ft_itoa_base(va_arg(args, unsigned), 16);
	return (buf);
}

void			hex_capital(char *buf)
{
	int			i;

	i = -1;
	while (buf[++i])
	{
		if (buf[i] >= 'a' && buf[i] <= 'z')
			buf[i] = buf[i] - 32;
	}
}

char			*zero_tunage_2(char *arg, t_nigga **nig)
{
	char		*var;

	var = NULL;
	if (((*nig)->hash && (*nig)->p_s == (int)ft_strlen(arg)) ||
		(arg[0] != '0' && arg[1] != 'x' && (*nig)->hash))
		var = ft_strjoin("0x", arg);
	else if (arg[1] != 'x' && (*nig)->hash)
	{
		arg[0] = '0';
		arg[1] = 'x';
		var = ft_strdup(arg);
	}
	else
		var = ft_strdup(arg);
	return (var);
}

void			zero_tunage_0_1(char **arr1, char *tmp, t_nigga **nig)
{
	(*arr1) = ft_strnew((*nig)->m_s);
	fill2((*arr1), (*nig)->m_s);
	fill_wz_zero((*arr1));
	custom_strcpy((*arr1) + (*nig)->m_s - ft_strlen(tmp), tmp);
	if ((*nig)->hash)
		(*arr1)[1] = 'x';
}

char			*zero_tunage(char *tmp, t_nigga **nig)
{
	char		*arr1;
	char		*var;

	var = NULL;
	arr1 = NULL;
	if ((*nig)->p_s > (int)ft_strlen(tmp))
	{
		arr1 = ft_strnew((*nig)->p_s);
		fill2(arr1, (*nig)->p_s);
		fill_wz_zero(arr1);
		custom_strcpy(arr1 + (*nig)->p_s - ft_strlen(tmp), tmp);
	}
	else if (!(*nig)->p_s && !(*nig)->dot && (*nig)->zero &&
		(*nig)->minus != '-')
	{
		zero_tunage_0_1(&arr1, tmp, nig);
	}
	else
		arr1 = ft_strdup(tmp);
	var = zero_tunage_2(arr1, nig);
	free(arr1);
	return (var);
}
