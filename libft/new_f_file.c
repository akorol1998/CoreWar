/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_f_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 15:29:00 by akorol            #+#    #+#             */
/*   Updated: 2019/04/17 15:29:01 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				round_f(long long buf, long long buf2, double *onum)
{
	long long trash;

	if (buf < 0)
	{
		buf *= -1;
		buf2 *= -1;
	}
	trash = buf % 10;
	if (buf > buf2 && !trash)
	{
		if ((*onum) < 0)
			(*onum) += -1;
		else if ((*onum) > 0)
			(*onum) += 1;
		return (1);
	}
	return (0);
}

int				replace_function(long long *buf, long long buf2, double *onum)
{
	if (round_f(*buf, buf2, onum))
		return (1);
	else
		return (0);
}
