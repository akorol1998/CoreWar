/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_shit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 14:49:10 by akorol            #+#    #+#             */
/*   Updated: 2019/03/19 14:49:14 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long double	casting_f(t_nigga **nig, va_list args)
{
	double	box;

	if ((*nig)->width == 'L')
		box = (long double)va_arg(args, double);
	else
		box = va_arg(args, double);
	return (box);
}

void		piece_f_shit(char const *str, t_nigga **nig, va_list args)
{
	char		*area;

	area = ft_strsub(str, 0, (*nig)->conv - str);
	check_min_width(area, nig);
	if (!(*nig)->dot)
		(*nig)->p_s = 6;
	free(area);
	tuning_f(nig, args);
}

char		*remainder_zeros(double *num, long long *i, t_nigga **nig)
{
	char			*buffer;
	double			copy;
	long long		counter;
	long long		a;

	copy = *num;
	counter = 0;
	while ((a = (copy * 10)) == 0 && ++(*i) < (*nig)->p_s)
	{
		copy *= 10;
		counter++;
	}
	buffer = ft_strnew(counter);
	fill2(buffer, counter);
	fill_wz_zero(buffer);
	while (counter)
	{
		*num *= 10;
		counter--;
	}
	return (buffer);
}

void		tuning_f_small_part(char **part_1, char **part_2,
	double num, t_nigga **nig)
{
	int64_t data;
	double	mynum;

	mynum = num;
	(*part_2) = tuning_f_2(mynum, &num, nig);
	(*part_1) = tuning_f_1(num, nig);
	if (num == 0)
	{
		data = *((int64_t *)&num);
		if (data < 0)
			(*nig)->sign = '-';
	}
	else
		(*nig)->sign = num < 0 ? '-' : '+';
}
