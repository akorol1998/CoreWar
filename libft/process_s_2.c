/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_s_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 17:06:49 by akorol            #+#    #+#             */
/*   Updated: 2019/03/19 17:06:50 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		last_piece(char *fin, t_nigga **nig)
{
	char	*buf;
	char	c;

	c = *(*nig)->conv;
	if ((*nig)->out)
	{
		buf = (*nig)->out;
		(*nig)->out = ft_strjoin((*nig)->out, fin);
		free(buf);
	}
	else
		(*nig)->out = ft_strdup(fin);
	free(fin);
}

void		concatenate(char *fin, t_nigga **nig)
{
	char	*buf;

	if ((*nig)->out)
	{
		buf = (*nig)->out;
		(*nig)->out = ft_strjoin((*nig)->out, fin);
		free(buf);
	}
	else
		(*nig)->out = ft_strdup(fin);
}

void		pre_tuner(char const **str, t_nigga **nig)
{
	int		i;

	i = 0;
	while (*str && (*str)[i] && (*str)[i] != '%')
		++i;
	(*str) += i;
	(*nig)->conv = (*str);
}

void		pick_width(char *fmt, t_nigga **nig)
{
	int		i;
	char	*buf;

	i = 0;
	while (fmt && fmt[i] && ft_isdigit(fmt[i]))
		++i;
	buf = ft_strsub(fmt, 0, i);
	(*nig)->m_s = ft_atoi(buf);
	free(buf);
}

void		pick_precision(char *fmt, t_nigga **nig)
{
	int		i;
	char	*buf;

	i = 0;
	while (fmt && fmt[i] && ft_isdigit(fmt[i]))
		++i;
	buf = ft_strsub(fmt, 0, i);
	(*nig)->p_s = ft_atoi(buf);
	free(buf);
}
