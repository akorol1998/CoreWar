/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buf_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 16:51:10 by akorol            #+#    #+#             */
/*   Updated: 2019/07/18 16:51:29 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core_war.h"

int			buf_manager(t_pack *data, char *fst)
{
	char	**arr;

	arr = ft_strsplit(data->buf, ',');
	data->w = 0;
	read_ld_args(data, arr);
	for (int j = 0;arr[j];j++)
		ft_printf("%s\n", arr[j]);
	ft_printf("arg1 - 1[%d] arg2 - 2[%d] arg3 - 3[%d]\n", data->arg1, data->arg2, data->arg3);
	fst = NULL;
	system("leaks asm");
	exit(1);
}