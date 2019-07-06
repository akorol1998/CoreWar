/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuner.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 12:13:42 by akorol            #+#    #+#             */
/*   Updated: 2019/01/15 16:19:22 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	tuner_part_2(char const **point, t_nigga **nig, va_list args)
{
	char	c;

	c = *(*nig)->conv;
	if (c == 'p')
		process_piece_p(*point, nig, args);
	else if (c == 'o' || c == 'u')
	{
		process_piece(*point, nig);
		conv_u(nig, args);
	}
	else if (c == 'f')
		piece_f_shit(*point, nig, args);
	else if (c == 'x' || c == 'X')
		piece_hex_shit(*point, nig, args);
	if (!(*nig)->conv)
		pre_tuner(point, nig);
	else
		(*point) = (*nig)->conv + 1;
	fill_my_nigga(&(*nig)->next);
	(*nig) = (*nig)->next;
}

char	*tuner_inner(char *buf, char const **point, va_list args, t_nigga **nig)
{
	char	c;

	c = *(*nig)->conv;
	buf = process_piece_c(*point, nig);
	if (c == '%')
		buf = conversion_percent(buf, nig);
	else
		buf = conversion_c(buf, nig, args);
	return (buf);
}

void	tuner(char const **point, t_nigga **nig, va_list args)
{
	char	*buf;
	char	c;

	buf = NULL;
	c = *(*nig)->conv;
	if ((*nig)->conv && ft_strlen(*point))
	{
		if (c == 'd' || c == 'i')
		{
			process_piece(*point, nig);
			conversion_d(nig, args);
		}
		else if (c == 'c' || c == '%')
		{
			buf = tuner_inner(buf, point, args, nig);
		}
		else if (c == 's')
			process_piece_s(*point, nig, args);
		if (buf)
			free(buf);
		tuner_part_2(point, nig, args);
	}
}
