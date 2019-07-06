/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_u_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 14:37:49 by akorol            #+#    #+#             */
/*   Updated: 2019/03/19 14:38:02 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*cond_a_part_1(int g, char *temp, t_nigga **nig)
{
	char		*box;

	g = (int)ft_strlen(temp) > g ? (int)ft_strlen(temp) : g;
	box = ft_strnew(g);
	fill2(box, g);
	if ((*nig)->minus)
		custom_strcpy(box, temp);
	else
		custom_strcpy(box + g - ft_strlen(temp), temp);
	if (temp)
		free(temp);
	return (box);
}

char			*cond_a(int g, int len, char *digits, t_nigga **nig)
{
	char		*temp;

	temp = NULL;
	if ((*nig)->p_s > len)
	{
		temp = cond_part_1(nig);
		custom_strcpy(temp + ft_strlen(temp) - ft_strlen(digits), digits);
	}
	else if ((*nig)->zero && !(*nig)->p_s &&
		(*nig)->minus != '-' && !(*nig)->dot)
	{
		temp = cond_part_2(nig);
		custom_strcpy(temp + ft_strlen(temp) - ft_strlen(digits), digits);
	}
	else
		check_weather_o(digits, &temp, nig);
	return (cond_a_part_1(g, temp, nig));
}

void			conv_u_part_1(char *transfer, char *digits, t_nigga **nig)
{
	char		*buf;

	buf = NULL;
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

void			conv_u(t_nigga **nig, va_list args)
{
	char		*digits;
	char		*transfer;
	int			g;

	if (*(*nig)->conv == 'u')
		digits = open_u_conversion(nig, args);
	else
		digits = open_o_conv(nig, args);
	if (digits[0] == '0')
	{
		zero_case_pure_function(nig);
		free(digits);
	}
	else
	{
		g = find_greater((*nig)->m_s, (*nig)->p_s);
		if (g > (int)ft_strlen(digits))
		{
			transfer = cond_a(g, ft_strlen(digits), digits, nig);
		}
		else
			transfer = cond_b(digits, nig);
		conv_u_part_1(transfer, digits, nig);
	}
}
