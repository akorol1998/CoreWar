/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 10:12:05 by akorol            #+#    #+#             */
/*   Updated: 2019/07/17 10:12:23 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core_war.h"

// {"live", 1, {T_DIR}, 1, 10, "alive", 0, 0}

void		args_to_cmnds(t_pack *data, char **arr)
{
	int			i;
	int			j;

	current_cmnds_position(data);
	i = data->w;
	j = -1;
	while (++j < data->arg_len) //Custom number of arguments
	{
		data->cmnds[data->l][i] = ft_strdup(arr[j]);
		i++;
	}
}

int			handle_live(t_pack *data, char **arr)
{
	int		res;

	res = 0;
	if (arr[0] && arr[0][0] == '%')
	{	
		if (arr[0][1] == ':'
		&& direct_label(data, arr[0] + 2))
		{
			res = 1;
		}
		else if (direct_number(data, arr, 0))
		{
			res = 1;
		}
		else
			res = 0;
	}
	if (res)
	{
		args_to_cmnds(data, arr);
		return (1);
	}
	else
		return (0);
}