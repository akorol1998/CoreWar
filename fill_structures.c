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
	while (data->tokens[++i])
	{
		j = -1;
		while (data->tokens[i][++j])
			ft_printf("%s ", data->tokens[i][j]);
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
	data->tokens = NULL;
	data->name = NULL;
	data->comment = NULL;
	data->buf = NULL;
	data->dsc = 0;
	data->line = 0;
	data->w = 0;
	data->arg1 = 0;
	data->arg2 = 0;
	data->arg3 = 0;
	// data->min = 0;
	// data->max = 0;
	data->bytes = 0;
	data->lbl = NULL;
	data->file_lines = 0;
	return (data);
}
