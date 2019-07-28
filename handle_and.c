/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_and.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 09:42:58 by akorol            #+#    #+#             */
/*   Updated: 2019/07/27 09:43:41 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core_war.h"

// {"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
// "et (and  r1, r2, r3   r1&r2 -> r3", 1, 0}
static int	thrd_stage(char **arr)
{
	int			res;

	res = 0;
	if (arr[2] && arr[2][0] == 'r' && register_check(arr[2]))
		res = 1;
	else
		res = 0;
	return (res);
}

static int	scnd_stage(t_pack *data, char **arr)
{
	int		res;

	res = 0;
	if (arr[1] && arr[1][0] == 'r' && register_check(arr[1]))
		res = thrd_stage(arr);
	else if (arr[1][0] == '%')
	{
		if (arr[1][1] == ':' && direct_label(data, arr[1] + 2))
			res = thrd_stage(arr);
		else if (direct_number(data, arr, 1))
			res = thrd_stage(arr);
		else
			res = 0;
	}
	else if (indirect_validation(data, arr[1]) )
		res = thrd_stage(arr);
	else
		res = 0;
	return (res);
}

int			handle_and(t_pack *data, char **arr)
{
	int		res;

	res = 0;
	if (arr[0] && arr[0][0] == 'r' && register_check(arr[0]))
		res = scnd_stage(data, arr);
	else if (arr[0][0] == '%')
	{
		if (arr[0][1] == ':' && direct_label(data, arr[0] + 2))
			res = scnd_stage(data, arr);
		else if (direct_number(data, arr, 0))
			res = scnd_stage(data, arr);
		else
			res = 0;
	}
	else if (indirect_validation(data, arr[0]))
		res = scnd_stage(data, arr);
	else
		res = 0;
	if (res)
		args_to_cmnds(data, arr);
	return (res);
}

void			scnd_arg(t_cmnd *cmnd, char **arr, int w)
{
	if (arr[w])
	{
		if (arr[w][0] == 'r' && register_check(arr[w]))
		{
			cmnd->type_code[3] = 1;
			cmnd->arg2 = 1;
		}
		else if (arr[w][0] == '%')
		{
			cmnd->type_code[2] = 1;
			cmnd->arg2 = 4;
		}
		else
		{
			cmnd->type_code[3] = 1;
			cmnd->type_code[2] = 1;
			cmnd->arg2 = 2;
		}
	}
	cmnd->type_code[5] = 1;
	cmnd->arg3 = 1;
	cmnd->type = 1;
	cmnd->size = cmnd->arg1 + cmnd->arg2 + cmnd->arg3 + cmnd->op + cmnd->type;
}

void			and_op_size(t_pack *da, int w)
{
	t_cmnd		*cmnd;
	char		**arr;

	cmnd = allocating_for_comm(da);
	cmnd->op = 1;
	arr = da->cmnds[da->l];
	if (!ft_strcmp(da->cmnds[da->l][da->w], "and"))
		cmnd->op_code = 0x06;
	else if (!ft_strcmp(da->cmnds[da->l][da->w], "or"))
		cmnd->op_code = 0x07;
	else if (!ft_strcmp(da->cmnds[da->l][da->w], "xor"))
		cmnd->op_code = 0x08;
	if (arr[++w])
	{
		if (arr[w][0] == 'r' && register_check(arr[w]))
		{
			cmnd->arg1 = 1;
			cmnd->type_code[1] = 1;
			scnd_arg(cmnd, arr, w + 1);
		}
		else if (arr[w][0] == '%')
		{
			cmnd->type_code[0] = 1;
			cmnd->arg1 = 4;
			scnd_arg(cmnd, arr, w + 1);
		}
		else
		{
			cmnd->type_code[0] = 1;
			cmnd->type_code[1] = 1;
			cmnd->arg1 = 2;
			scnd_arg(cmnd, arr, w + 1);
		}
		and_op_type_code(cmnd);
	}
}