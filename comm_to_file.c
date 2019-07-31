/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comm_to_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 15:35:54 by akorol            #+#    #+#             */
/*   Updated: 2019/07/31 15:36:01 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core_war.h"

void			comm_info_to_file(t_pack *da, int *idx)
{
	t_cmnd		*com;

	com = da->comm[*idx];
	write(da->dsc, &com->op_code, 1);
	if (com->type_c)
		write(da->dsc, &com->type_c, 1);
}

int			get_direct_number(t_pack *data, char **line, int w)
{
	int		i;
	char	*nbr;

	i = 0;
	while (line[w][++i])
	{
		if ((line[w][i] == '+' || (line[w][i] == '-' && i != 1)) ||
		(!ft_isdigit(line[w][i]) && line[w][i] != '+' && line[w][i] != '-'))
		{
			return (0);
		}
	}	
	nbr = ft_strsub(line[w], 1, i);
	i = ft_atoi(nbr);
	free(nbr);
	data = NULL;
	return (i);
}

int			get_indirect_number(char *line)
{
	int		i;
	char	*nbr;


	i = -1;
	while(line[++i])
		;
	nbr = ft_strndup(line, i);
	i = ft_atoi(nbr);
	free(nbr);
	return (i);
}

void		indirect_case(t_pack *da, int w, int i, int *idx)
{
	int		size;
	int		nbr;
	char	*lbl;

	lbl = NULL;
	if (!i)
		size = da->comm[*idx]->arg1;
	else if (i == 1)
		size = da->comm[*idx]->arg2;
	else if (i == 2)
		size = da->comm[*idx]->arg3;
	if (da->cmnds[da->l][w] && da->cmnds[da->l][w][0] == ':'
	&& (lbl = get_direct_label(da, da->cmnds[da->l][w] + 1)))
	{
		nbr = search_for_label(da, idx, lbl);
		write_to_file(da, size, nbr);
	}
	else
	{
		nbr = get_indirect_number(da->cmnds[da->l][w]);
		write_to_file(da, size, nbr);
	}
	free(lbl);
}
