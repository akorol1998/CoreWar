/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 17:58:10 by akorol            #+#    #+#             */
/*   Updated: 2019/01/16 17:41:53 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	what_sign(int *num, int *sign)
{
	int		left;

	if (*num == -2147483648)
	{
		*num = 214748364;
		*sign = 2;
		left = 8;
	}
	else if (*num < 0)
	{
		*num *= -1;
		*sign = 1;
	}
}

static	void	func1(char *s, int size, int n, int sign)
{
	s[size] = '\0';
	if (sign == 2)
		s[--size] = '8';
	while (--size >= 0)
	{
		s[size] = n % 10 + '0';
		n /= 10;
	}
}

char			*ft_itoa(int n)
{
	int		temp;
	int		size;
	int		sign;
	char	*box;

	size = 1;
	sign = 0;
	what_sign(&n, &sign);
	temp = n;
	while (temp /= 10)
		size++;
	size += sign;
	if ((box = ft_strnew(size)) == NULL)
		return (NULL);
	func1(box, size, n, sign);
	if (sign)
		box[0] = '-';
	return (box);
}
