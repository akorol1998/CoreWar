/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_processing0.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 12:41:30 by akorol            #+#    #+#             */
/*   Updated: 2019/01/15 16:20:52 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char const		*customize_string(char const *str, t_nigga **lopata)
{
	int			i;
	char		*del;
	char		*trash;

	i = 0;
	while (str[i] && str[i] != '%')
	{
		i++;
		if (str[i] == '%')
			(*lopata)->arg = 1;
	}
	if (i)
	{
		if (!(*lopata)->out)
			(*lopata)->out = ft_strsub(str, 0, i);
		else
		{
			del = (*lopata)->out;
			trash = ft_strsub(str, 0, i);
			(*lopata)->out = ft_strjoin((*lopata)->out, trash);
			free(del);
			free(trash);
		}
	}
	return (str + i);
}

char const		*double_percent_sign(char const *fmt, t_nigga **nig)
{
	char		*buf;

	while (fmt && *(fmt + 1) == '%')
	{
		if (!(*nig)->out)
			(*nig)->out = ft_strsub(fmt, 0, 1);
		else
		{
			buf = (*nig)->out;
			(*nig)->out = ft_strjoin((*nig)->out, "%");
			free(buf);
		}
		fmt = customize_string(fmt + 2, nig);
	}
	return (++fmt);
}

void			custom_width(char const *s, t_nigga **nig)
{
	int			i;
	char		c;

	i = 0;
	c = s[i];
	s++;
	while (s[i] && s[i] != c)
		i++;
	if (s[i] != c)
		(*nig)->width = c;
	else
		(*nig)->width = c - 32;
}

void			customize_flags_2(char const *s, int i, t_nigga **lopata)
{
	if ((s[i] == 'l' || s[i] == 'h' || s[i] == 'L') && !(*lopata)->width)
		custom_width((s + i), lopata);
	if (s[i] == '-')
		(*lopata)->minus = s[i];
	if (s[i] == '+')
		(*lopata)->plus = s[i];
	if (s[i] == '#')
		(*lopata)->hash = s[i];
	if (s[i] == '.')
		(*lopata)->dot = s[i];
	if (s[i] == ' ')
		(*lopata)->blank = s[i];
	if (!(*lopata)->zero && s[i] == '0' &&
		!ft_isdigit(s[i - 1]) && s[i - 1] != '.')
		(*lopata)->zero = 1;
	if (s[i] != '-' && s[i] != '+' && s[i] != ' ' && s[i] != '#')
		(*lopata)->invalid = 1;
}

void			customize_flags(char const *s, t_nigga **lopata)
{
	int			i;

	i = 0;
	while (s[i] && (s[i] != 'c' && s[i] != 's' && s[i] != 'p' &&
		s[i] != 'd' && s[i] != 'i' && s[i] != 'o' && s[i] != 'u'
		&& s[i] != 'x' && s[i] != 'f' && s[i] != 'X' && s[i] != '%'))
	{
		customize_flags_2(s, i, lopata);
		i++;
	}
	if (s[i] && (s[i] == 'c' || s[i] == 's' || s[i] == 'p' ||
		s[i] == 'd' || s[i] == 'i' || s[i] == 'o' || s[i] == '%'
		|| s[i] == 'u' || s[i] == 'x' || s[i] == 'f' || s[i] == 'X'))
	{
		(*lopata)->conv = s + i;
	}
}
