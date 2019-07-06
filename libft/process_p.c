/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 11:17:26 by akorol            #+#    #+#             */
/*   Updated: 2019/02/15 11:17:49 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		converter_p_part1(char *final, char *tmp, t_nigga **nig)
{
	final = ft_strnew((*nig)->m_s);
	fill2(final, (*nig)->m_s);
	if (!(*nig)->minus)
		custom_strcpy(final + (*nig)->m_s - ft_strlen(tmp), tmp);
	else
		custom_strcpy(final, tmp);
	last_piece(final, nig);
	free(tmp);
}

void		converter_p(t_nigga **nig, va_list args)
{
	char			*tmp;
	char			*final;

	tmp = ft_itoa_base(va_arg(args, unsigned long), 16);
	if (tmp[0] == '0')
	{
		zero_case_function(nig);
		free(tmp);
	}
	else
	{
		final = tmp;
		tmp = ft_strjoin("0x", final);
		free(final);
		if ((*nig)->m_s > (int)ft_strlen(tmp))
		{
			converter_p_part1(final, tmp, nig);
		}
		else
		{
			final = tmp;
			last_piece(final, nig);
		}
	}
}

void		process_piece_p(char const *fmt, t_nigga **nig, va_list args)
{
	process_piece(fmt, nig);
	converter_p(nig, args);
}
