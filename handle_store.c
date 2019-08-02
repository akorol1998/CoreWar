/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_store.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 11:30:42 by akorol            #+#    #+#             */
/*   Updated: 2019/07/27 11:30:49 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core_war.h"

int				handle_store(t_pack *data, char **arr)
{
	int		res;

	res = 0;
	if (arr && arr[0] && arr[0][0] == 'r' && register_check(arr[0]))
	{
		if (arr && arr[1] && arr[1][0] == 'r' && register_check(arr[1]))
			res = 1;
		else if (arr && arr[1] && indirect_validation(data, arr[1]))
			res = 1;
		else
			res = 0;
	}
	if (res)
		args_to_cmnds(data, arr);
	return (res);
}