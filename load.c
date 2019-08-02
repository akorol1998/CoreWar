/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 12:57:19 by akorol            #+#    #+#             */
/*   Updated: 2019/07/17 12:57:29 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core_war.h"

//{"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load", 1, 0}

int			check_2nd_arg(char **arr)
{
	if (arr[1] && arr[1][0] == 'r' && register_check(arr[1]))
		return (1);
	return (0);
}

int				handle_load(t_pack *data, char **arr)
{
	int		res;

	res = 0;

	if (arr[0] && arr[0][0] == '%')
	{
		if (arr[0][1] == ':'
		&& direct_label(data, arr[0] + 2))
		{
			res = check_2nd_arg(arr);
		}
		else if (direct_number(data, arr, 0))
		{
			res = check_2nd_arg(arr);
		}
		else
			res = 0;
	}
	else if (arr[0] && indirect_validation(data, arr[0]))
		res = check_2nd_arg(arr);
	else
		res = 0;
	if (res)
		args_to_cmnds(data, arr);
	return (res);
}

void			ld_op_size(t_pack *da, int w)
{
	t_cmnd		*cmnd;
	char		**arr;

	cmnd = allocating_for_comm(da);
	cmnd->op = 1;
	arr = da->cmnds[da->l];
	cmnd->arg2 = 1;
	cmnd->type = 1;
	if (!ft_strcmp(da->cmnds[da->l][w], "ld"))
		cmnd->op_code = 0x02;
	else if (!ft_strcmp(da->cmnds[da->l][w], "lld"))
		cmnd->op_code = 0x0d;
	if (arr[++w])
	{
		if (arr[w][0] == '%')
		{
			cmnd->type_code[0] = 1;
			cmnd->arg1 = 4;	
		}
		else
		{
			cmnd->type_code[0] = 1;
			cmnd->type_code[1] = 1;
			cmnd->arg1 = 2;	
		}
	}
	cmnd->type_code[3] = 1;
	and_op_type_code(cmnd);
	cmnd->size = cmnd->arg1 + cmnd->arg2 + cmnd->type + cmnd->op;
	
}