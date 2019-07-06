/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 11:35:27 by akorol            #+#    #+#             */
/*   Updated: 2019/01/16 17:41:24 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int						sign;
	unsigned long int		value;

	sign = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\v'
			|| *str == '\r' || *str == '\f')
		str++;
	if (*str == '-' || *str == '+')
	{
		sign = (*str == '-' ? -1 : 1);
		str++;
	}
	value = 0;
	while (*str && ft_isdigit(*str))
	{
		value = (value * 10) + (*str - '0');
		if (value >= 9223372036854775807 && sign == 1)
			return (-1);
		else if (value > 9223372036854775807 && sign == -1)
			return (0);
		str++;
	}
	return ((int)value * sign);
}
