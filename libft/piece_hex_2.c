/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece_hex_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 15:42:49 by akorol            #+#    #+#             */
/*   Updated: 2019/03/18 15:44:25 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*string_hex_tuning(int len, char *buf, char *tmp, t_nigga **nig)
{
	char	*new;

	buf = ft_strnew(len);
	fill2(buf, len);
	new = zero_tunage(tmp, nig);
	if ((*nig)->minus)
	{
		custom_strcpy(buf, new);
	}
	else
	{
		custom_strcpy(buf + ft_strlen(buf) - ft_strlen(new), new);
	}
	free(new);
	return (buf);
}

char			*hex_setup_2(int len, char *tmp, t_nigga **nig)
{
	char		*buf;

	buf = NULL;
	if (((*nig)->m_s > len || (*nig)->p_s > len))
	{
		if ((*nig)->p_s + 2 < (*nig)->m_s)
		{
			if ((*nig)->m_s - len < 2)
				(*nig)->m_s++;
			{
				buf = string_hex_tuning((*nig)->m_s, buf, tmp, nig);
			}
		}
		else
			buf = string_hex_tuning((*nig)->p_s + 2, buf, tmp, nig);
	}
	else
		buf = ft_strjoin("0x", tmp);
	return (buf);
}

char			*hex_setup(char *tmp, t_nigga **nig)
{
	char		*buf;
	int			len;

	buf = NULL;
	len = ft_strlen(tmp);
	if ((*nig)->hash)
	{
		buf = hex_setup_2(len, tmp, nig);
	}
	else
	{
		if ((*nig)->m_s > len || (*nig)->p_s > len)
		{
			buf = string_hex_tuning(ft_max((*nig)->m_s,
				(*nig)->p_s), buf, tmp, nig);
		}
		else
			buf = ft_strdup(tmp);
	}
	return (buf);
}

void			tuning_hex(t_nigga **nig, va_list args)
{
	char		*tmp;
	char		*result;

	tmp = hex_converter(nig, args);
	if (tmp[0] == '0')
	{
		zero_case_pure_function(nig);
		free(tmp);
	}
	else
	{
		result = hex_setup(tmp, nig);
		free(tmp);
		if (*(*nig)->conv == 'X')
			hex_capital(result);
		if ((*nig)->out)
		{
			tmp = (*nig)->out;
			(*nig)->out = ft_strjoin((*nig)->out, result);
			free(tmp);
		}
		else
			(*nig)->out = ft_strdup(result);
		free(result);
	}
}

void			piece_hex_shit(char const *str, t_nigga **nig, va_list args)
{
	char		*area;

	area = ft_strsub(str, 0, (*nig)->conv - str);
	check_min_width(area, nig);
	free(area);
	tuning_hex(nig, args);
}
