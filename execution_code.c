/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_code.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 16:38:55 by akorol            #+#    #+#             */
/*   Updated: 2019/07/27 16:39:08 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core_war.h"

void			count_execution_line_size_2(t_pack *da, int w)
{
	if (!ft_strcmp(da->cmnds[da->l][w], "or"))
		and_op_size(da, w);
	else if (!ft_strcmp(da->cmnds[da->l][w], "xor"))
		and_op_size(da, w);
	else if (!ft_strcmp(da->cmnds[da->l][w], "ldi"))
		load_index_op_size(da, w);
	else if (!ft_strcmp(da->cmnds[da->l][w], "fork"))
		live_op_size(da, w);
	else if (!ft_strcmp(da->cmnds[da->l][w], "lld"))
		ld_op_size(da, w);
	else if (!ft_strcmp(da->cmnds[da->l][w], "lldi"))
		load_index_op_size(da, w);
	else if (!ft_strcmp(da->cmnds[da->l][w], "lfork"))
		live_op_size(da, w);
	else if (!ft_strcmp(da->cmnds[da->l][w], "aff"))
		live_op_size(da, w);
}

void			count_execution_line_size(t_pack *da, int w)
{
	if (!ft_strcmp(da->cmnds[da->l][w], "and"))
		and_op_size(da, w);
	else if (!ft_strcmp(da->cmnds[da->l][w], "ld"))
		ld_op_size(da, w);
	else if (!ft_strcmp(da->cmnds[da->l][w], "sti"))
		sti_op_size(da, w);
	else if (!ft_strcmp(da->cmnds[da->l][w], "live"))
		live_op_size(da, w);
	else if (!ft_strcmp(da->cmnds[da->l][w], "zjmp"))
		live_op_size(da, w);
	else if (!ft_strcmp(da->cmnds[da->l][w], "st"))
		st_op_size(da, w);
	else if (!ft_strcmp(da->cmnds[da->l][w], "add"))
		add_sub_op_size(da, w);
	else if (!ft_strcmp(da->cmnds[da->l][w], "sub"))
		add_sub_op_size(da, w);
	count_execution_line_size_2(da, w);
}

void			count_lines_size(t_pack *da)
{
	da->l = -1;
	while (da->cmnds[++da->l])
	{
		da->w = -1;
		while (da->cmnds[da->l][++da->w])
		{
			if (!da->w && compare_func(da->cmnds[da->l][da->w], da))
				count_execution_line_size(da, da->w);
			else if (!da->w && da->cmnds[da->l][da->w + 1] &&
			compare_func(da->cmnds[da->l][da->w + 1], da))
				count_execution_line_size(da, da->w + 1);
		}
	}
	
}

void			execution_code(t_pack *data)
{
	// t_cmnd		*cmnd;
	// char		c = 52;
	int			i;
	int			size;
	int			n;

	count_lines_size(data);
	go_through_ops(data);
	lseek(data->dsc, data->pos, 0);
	i = -1;
	size = 0;
	while (data->comm[++i])
		size += data->comm[i]->size;
	i = 4;
	while (i--)
	{
		n = size >> 8 * i;
		write(data->dsc, &n, 1);
	}
	system("leaks asm");
	exit(1);
	// write(data->dsc, &c, 1);
	// a = c >> 16;
	// write(data->dsc, &a, 1);
	// a = c >> 8;
	// write(data->dsc, &a, 1);
	// a = c;
	// write(data->dsc, &a, 1);
	// cmnd = data->comm[15];
	// ft_printf("cmnd->op %d\n", cmnd->op);
	// ft_printf("cmnd->type %d\n", cmnd->type);
	// ft_printf("cmnd->arg1 %d\n", cmnd->arg1);
	// ft_printf("cmnd->arg2 %d\n", cmnd->arg2);
	// ft_printf("cmnd->arg3 %d\n", cmnd->arg3);	
	// ft_printf("cmnd->size %d\n", cmnd->size);
}