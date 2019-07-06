/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 18:45:52 by akorol            #+#    #+#             */
/*   Updated: 2019/02/13 18:46:11 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		custom_strcpy(char *str1, char *str2)
{
	size_t	i;
	size_t	j;

	j = ft_strlen(str2);
	i = 0;
	while (i < j)
	{
		str1[i] = str2[i];
		i++;
	}
}

void		leng_compar_2(char *tmp, t_nigga **nig)
{
	char	*final;

	(final) = ft_strnew((*nig)->m_s);
	fill2((final), (*nig)->m_s);
	if (!(*nig)->minus)
		custom_strcpy((final) + (*nig)->m_s - ft_strlen(tmp), tmp);
	else
		custom_strcpy((final), tmp);
	concatenate((final), nig);
	free(final);
}

void		length_comparator(t_nigga **nig, va_list args)
{
	char	*buf;
	char	*str;
	char	*tmp;

	buf = va_arg(args, char *);
	if (!buf)
		str = ft_strdup("(null)");
	else
		str = ft_strdup(buf);
	if ((*nig)->p_s < (int)ft_strlen(str) && (*nig)->dot)
		tmp = ft_strsub(str, 0, (*nig)->p_s);
	else
		tmp = ft_strdup(str);
	if ((*nig)->m_s > (int)ft_strlen(tmp))
		leng_compar_2(tmp, nig);
	else
		concatenate(tmp, nig);
	free(tmp);
	free(str);
}

void		process_piece_s(char const *fmt, t_nigga **nig, va_list args)
{
	char	*buf;
	char	*p;
	char	*s;
	int		i;

	buf = (char *)fmt;
	s = ft_strchr(buf, *(*nig)->conv);
	buf = ft_strsub(buf, 0, s - buf);
	p = ft_strchr(buf, '.');
	if (p)
	{
		(*nig)->dot = 1;
		pick_precision(++p, nig);
	}
	i = 0;
	while (buf[i] && buf[i] && !ft_isdigit(buf[i]) && buf[i] != '.')
		i++;
	if (buf[i] == '.')
		(*nig)->m_s = 0;
	pick_width(buf + i, nig);
	length_comparator(nig, args);
	free(buf);
}
