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
	int			res;

	res = 0;
	ft_printf("ARGUMENT <#3");
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
