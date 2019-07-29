/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 16:21:57 by akorol            #+#    #+#             */
/*   Updated: 2019/07/27 09:42:49 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core_war.h"

int			handle_add(t_pack *data, char **arr)
{
	int		res;

	res = 0;
	if (arr[0] && arr[0][0] == 'r' && register_check(arr[0]))
	{
		if (arr[1] && arr[1][0] == 'r' && register_check(arr[1]))
		{
			if (arr[2] && arr[2][0] == 'r' && register_check(arr[2]))
			{
				res = 1;
			}
			else
				res = 0;
		}
		else
			res = 0;
	}
	else
		res = 0;
	if (res)
		args_to_cmnds(data, arr);
	return (res);
}

void		add_sub_op_size(t_pack *da, int w)
{
	t_cmnd	*cmnd;
	
	cmnd = allocating_for_comm(da);
	if (!ft_strcmp(da->cmnds[da->l][da->w], "add"))
		cmnd->op_code = 0x04;
	else if (!ft_strcmp(da->cmnds[da->l][da->w], "sub"))
		cmnd->op_code = 0x05;
	cmnd->op = 1;
	cmnd->type = 1;
	cmnd->arg1 = 1;
	cmnd->arg2 = 1;
	cmnd->arg3 = 1;
	cmnd->type_code[1] = 1;
	cmnd->type_code[3] = 1;
	cmnd->type_code[5] = 1;
	and_op_type_code(cmnd);
	cmnd->size = cmnd->op + cmnd->type + cmnd->arg1 + cmnd->arg2 + cmnd->arg3;
	w = 1;
}