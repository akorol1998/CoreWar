/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nan_inf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 11:32:55 by akorol            #+#    #+#             */
/*   Updated: 2019/03/22 11:43:34 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		nan_inf_function(double num, t_nigga **nig)
{
	char	*buf;

	buf = NULL;
	if (num != num)
		buf = ft_strdup("nan");
	else if (num * 2 == num && num != 0)
	{
		if (num > 0 && (*nig)->blank && (*nig)->plus != '+')
			buf = ft_strdup(" inf");
		else if (num > 0 && (*nig)->plus == '+')
			buf = ft_strdup("+inf");
		else if (num > 0)
			buf = ft_strdup("inf");
		else if (num < 0)
			buf = ft_strdup("-inf");
	}
	nan_inf_string(buf, nig);
	free(buf);
}

void		nan_inf_string(char *str, t_nigga **nig)
{
	char	*buf;

	buf = NULL;
	if ((int)ft_strlen(str) > (*nig)->m_s)
		buf = ft_strdup(str);
	else
	{
		buf = ft_strnew((*nig)->m_s);
		fill2(buf, (*nig)->m_s);
		if (!(*nig)->minus)
			custom_strcpy(buf + (*nig)->m_s - ft_strlen(str), str);
		else
			custom_strcpy(buf, str);
	}
	concatenate(buf, nig);
	free(buf);
}
