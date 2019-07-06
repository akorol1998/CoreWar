/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filling.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 17:48:10 by akorol            #+#    #+#             */
/*   Updated: 2019/01/14 17:48:11 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	fill_my_nigga(t_nigga **nig)
{
	(*nig) = (t_nigga*)malloc(sizeof(t_nigga));
	(*nig)->m_s = 0;
	(*nig)->p_s = 0;
	(*nig)->invalid = 0;
	(*nig)->conv = NULL;
	(*nig)->width = 0;
	(*nig)->blank = 0;
	(*nig)->out = NULL;
	(*nig)->percent = 0;
	(*nig)->hash = 0;
	(*nig)->zero = 0;
	(*nig)->sign = '+';
	(*nig)->minus = 0;
	(*nig)->plus = 0;
	(*nig)->dot = 0;
	(*nig)->next = NULL;
	(*nig)->arg = 0;
	(*nig)->slashz = 0;
}

void	fill_zero(char *buf, int size, int fill)
{
	int	i;
	int	len;

	i = -1;
	while (++i < size)
		buf[i] = ' ';
	len = ft_strlen(buf);
	while (fill != 0)
	{
		buf[len - fill] = '0';
		fill--;
	}
}

void	fill2(char *str, int len)
{
	int	i;

	i = -1;
	while (++i < len)
		str[i] = ' ';
}

void	fill_wz_zero(char *str)
{
	while (str && *str)
	{
		*str = *str == ' ' ? '0' : *str;
		str++;
	}
}
