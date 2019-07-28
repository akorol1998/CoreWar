/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_and_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 16:53:14 by akorol            #+#    #+#             */
/*   Updated: 2019/07/28 16:53:31 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core_war.h"

int				two_to_power(int a)
{
	int			t;
	int			i;

	t = 2;
	i = 0;
	while (++i < a)
		t *= 2;
	return (t);
}

void			and_op_type_code(t_cmnd *cmnd)
{
	int			i;
	int			nmbr;

	i = 8;
	nmbr = 0;
	while (--i >= 0)
	{
		nmbr += cmnd->type_code[i] * (two_to_power(7 - i));
	}
	cmnd->type = nmbr;
	ft_printf("My nbr - %p\n", nmbr);
}