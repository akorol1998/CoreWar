/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_structures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 13:21:32 by akorol            #+#    #+#             */
/*   Updated: 2019/07/06 13:21:50 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core_war.h"

void		print_tokens(t_pack *data)
{

	int		i;
	int		j;

	i = -1;
	j = -1;
	while (data->cmnds[++i])
	{
		j = -1;
		while (data->cmnds[i][++j])
			ft_printf("%s ", data->cmnds[i][j]);
		ft_printf("\n", i);
	}	
}

void		fill_ops(t_pack *data)
{
	data->op = (char**)malloc(sizeof(char*) * 17);
	data->op[16] = NULL;
	data->op[0] = ft_strdup("live");
	data->op[1] = ft_strdup("ld");
	data->op[2] = ft_strdup("st");
	data->op[3] = ft_strdup("add");
	data->op[4] = ft_strdup("sub");
	data->op[5] = ft_strdup("and");
	data->op[6] = ft_strdup("or");
	data->op[7] = ft_strdup("xor");
	data->op[8] = ft_strdup("zjmp");
	data->op[9] = ft_strdup("ldi");
	data->op[10] = ft_strdup("sti");
	data->op[11] = ft_strdup("fork");
	data->op[12] = ft_strdup("lld");
	data->op[13] = ft_strdup("lldi");
	data->op[14] = ft_strdup("lfork");
	data->op[15] = ft_strdup("aff");
}

void		fill_cmnds(t_pack *data)
{
	int		i;

	i = -1;
	data->cmnds = (char***)malloc(sizeof(char**) * CHAMP_MAX_SIZE + 1);
	while (++i <=CHAMP_MAX_SIZE)
		data->cmnds[i] = NULL;
}

t_pack		*fill_data(void)
{
	t_pack	*data;
	int		i;

	i = -1;
	data = (t_pack*)malloc(sizeof(t_pack));
	data->labels = (char**)malloc(sizeof(char*) * CHAMP_MAX_SIZE + 1);
	while (++i <= CHAMP_MAX_SIZE)
		data->labels[i] = NULL;
	fill_ops(data);
	fill_cmnds(data);
	allocate_comm(data);
	data->file_name = NULL;
	data->name = NULL;
	data->comment = NULL;
	data->buf = NULL;
	data->dsc = 0;
	data->l = -1;
	data->w = 0;
	data->pos = 0;
	data->arg_len = 0;
	data->idx = 0;
	data->bytes = 0;
	data->lbl = NULL;
	return (data);
}

t_cmnd		*allocating_for_comm(t_pack *da)
{
	int		i;

	i = -1;
	while (da->comm[++i])
		;
	da->comm[i] = (t_cmnd*)malloc(sizeof(t_cmnd));
	da->comm[i]->op = 0;
	da->comm[i]->type = 0;
	da->comm[i]->arg1 = 0;
	da->comm[i]->arg2 = 0;
	da->comm[i]->arg3 = 0;
	da->comm[i]->size = 0;
	return (da->comm[i]);
}