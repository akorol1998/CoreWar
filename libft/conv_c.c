/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 14:02:18 by akorol            #+#    #+#             */
/*   Updated: 2019/02/12 14:02:23 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		align_c(char *buf, t_nigga **nig)
{
	char	*tmp;

	tmp = NULL;
	if ((*nig)->out)
	{
		tmp = (*nig)->out;
		(*nig)->out = ft_strjoin((*nig)->out, buf);
		free(tmp);
	}
	else
		(*nig)->out = ft_strdup(buf);
}

char		*conversion_percent(char *buf, t_nigga **nig)
{
	int		flag;

	flag = 0;
	if (ft_strlen(buf))
	{
		if ((*nig)->minus)
			buf[0] = '%';
		else
			buf[ft_strlen(buf) - 1] = '%';
	}
	else
	{
		free(buf);
		buf = ft_strnew(1);
		buf[0] = '%';
		flag = 1;
	}
	align_c(buf, nig);
	return (buf);
}

char		*conversion_c(char *buf, t_nigga **nig, va_list args)
{
	char	c;

	c = va_arg(args, int);
	if (c == '\0')
		zero_case_pure_function(nig);
	else
	{
		if (ft_strlen(buf))
		{
			if ((*nig)->minus)
				buf[0] = c;
			else
				buf[ft_strlen(buf) - 1] = c;
		}
		else
		{
			free(buf);
			buf = ft_strnew(1);
			buf[0] = c;
		}
		align_c(buf, nig);
	}
	return (buf);
}
