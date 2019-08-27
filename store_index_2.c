/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_index_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 10:35:40 by akorol            #+#    #+#             */
/*   Updated: 2019/07/14 10:36:31 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core_war.h"

void			sti_op_size(t_pack *da, int w)
{
	t_cmnd		*cmnd;
	char		**arr;

	cmnd = allocating_for_comm(da);
	cmnd->op = 1;
	arr = da->cmnds[da->l];
	cmnd->arg1 = 1;
	cmnd->op_code = 0x0b;
	cmnd->type_code[1] = 1;
	w++;
	sti_op_size_2(cmnd, arr, w);
}

void			st_op_size_2(t_cmnd *cmnd, char **arr, int w)
{
	if (arr[++w])
	{
		if (arr[w][0] == 'r' && register_check(arr[w]))
		{
			cmnd->type_code[3] = 1;
			cmnd->arg2 = 1;
		}
		else
		{
			cmnd->type_code[3] = 1;
			cmnd->type_code[2] = 1;
			cmnd->arg2 = 2;
		}
	}
	and_op_type_code(cmnd);
	cmnd->size = cmnd->op + cmnd->type + cmnd->arg1 + cmnd->arg2;
}

void			st_op_size(t_pack *da, int w)
{
	t_cmnd		*cmnd;
	char		**arr;

	cmnd = allocating_for_comm(da);
	arr = da->cmnds[da->l];
	cmnd->op = 1;
	cmnd->type = 1;
	cmnd->arg1 = 1;
	cmnd->type_code[1] = 1;
	cmnd->op_code = 0x03;
	++w;
	st_op_size_2(cmnd, arr, w);
}
