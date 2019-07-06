/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_o.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 13:04:38 by akorol            #+#    #+#             */
/*   Updated: 2019/02/15 13:06:52 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*open_o_conv(t_nigga **nig, va_list args)
{
	char	*buf;

	if ((*nig)->width == 'l')
		buf = ft_itoa_base(va_arg(args, unsigned long), 8);
	else if ((*nig)->width == 'L')
		buf = ft_itoa_base(va_arg(args, unsigned long long), 8);
	else if ((*nig)->width == 'h')
		buf = ft_itoa_base((unsigned short)va_arg(args, int), 8);
	else if ((*nig)->width == 'H')
		buf = ft_itoa_base((unsigned char)va_arg(args, int), 8);
	else
		buf = ft_itoa_base(va_arg(args, unsigned int), 8);
	return (buf);
}
