/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_index.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 10:35:10 by akorol            #+#    #+#             */
/*   Updated: 2019/07/14 10:35:11 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core_war.h"

int				thrd_stage(t_pack *data, char **arr)
{
	int			res;

	res = 0;
	if (arr[2] && arr[2][0] == 'r' && register_check(arr[2]))
	{
		res = 1;
	}
	else if (arr[2] && arr[2][0] == '%')
	{
		if (arr[2][1] == ':' && direct_label(data, arr[2] + 2))
		{
			res = 1;
		}
		else if (direct_number(data, arr, 2))
		{
			res = 1;
		}
		else
			res = 0;
	}
	return (res);
}

int				scnd_stage(t_pack *data, char **arr)
{
	int			res;

	res = 0;
	if (arr[1] && arr[1][0] == 'r' && register_check(arr[1]))
		res = thrd_stage(data, arr);
	else if (arr[1] && arr[1][0] == '%')
	{
		if (arr[1][1] == ':' && direct_label(data, arr[1] + 2))
			res = thrd_stage(data, arr);
		else if (direct_number(data, arr, 1))
			res = thrd_stage(data, arr);
		else
			res = 0;
	}
	else if (indirect_validation(data, arr[1]))
		res = thrd_stage(data, arr);
	else
		res = 0;
	return (res);
}

int				handle_sti(t_pack *data, char **arr)
{
	int			res;

	res = 0;
	if (arr[0] && arr[0][0] == 'r' && register_check(arr[0]))
		res = scnd_stage(data, arr);
	else
		res = 0;
	if (res)
		args_to_cmnds(data, arr);
	return (res);
}

void			arg2_stage(t_cmnd *cmnd, char **arr, int w)
{
	if (arr[w] && arr[w][0] == 'r' && register_check(arr[w]))
	{
		cmnd->arg3 = 1;
		cmnd->type_code[5] = 1;
	}
	else
	{
		cmnd->type_code[4] = 1;
		cmnd->arg3 = 2;
	}
	cmnd->type = 1;
	and_op_type_code(cmnd);
	cmnd->size = cmnd->arg1 + cmnd->arg2 + cmnd->arg3 + cmnd->type + cmnd->op;
}

void			sti_op_size_2(t_cmnd *cmnd, char **arr, int w)
{
	if (arr[++w])
	{
		if (arr[w][0] == 'r' && register_check(arr[w]))
		{
			cmnd->type_code[3] = 1;
			cmnd->arg2 = 1;
			arg2_stage(cmnd, arr, w + 1);
		}
		else if (arr[w][0] == '%')
		{
			cmnd->type_code[2] = 1;
			cmnd->arg2 = 2;
			arg2_stage(cmnd, arr, w + 1);
		}
		else
		{
			cmnd->type_code[2] = 1;
			cmnd->type_code[3] = 1;
			cmnd->arg2 = 2;
			arg2_stage(cmnd, arr, w + 1);
		}
	}
}
