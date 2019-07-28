/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_aff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 10:52:39 by akorol            #+#    #+#             */
/*   Updated: 2019/07/27 10:52:45 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core_war.h"

int			handle_aff(t_pack *data, char **arr)
{
	int		res;

	res = 0;
	if (arr && arr[0] && arr[0][0] == 'r' && register_check(arr[0]))
		res = 1;
	if (res)
		args_to_cmnds(data, arr);
	return (res);
}

void		aff_op_size(t_pack *da, int w)
{
	t_cmnd	*cmnd;

	cmnd = allocating_for_comm(da);
	cmnd->arg1 = 1;
	cmnd->op = 1;
	cmnd->type = 1;
	cmnd->size = cmnd->arg1 + cmnd->op + cmnd->type;
	w = 0;
}
