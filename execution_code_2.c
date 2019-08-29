/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_code_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 16:17:48 by akorol            #+#    #+#             */
/*   Updated: 2019/07/28 16:17:57 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core_war.h"

int			register_nbr(char *line, int i)
{
	char	*nbr;
	int		j;

	j = -1;
	nbr = ft_strsub(line, 1, i - 1);
	while (nbr[++j])
	{
		if (nbr[j] == '+' || nbr[j] == '-')
			return (0);
	}
	j = ft_atoi(nbr);
	free(nbr);
	return (j);
}

int			get_register(char *line)
{
	int		i;
	int		res;
	int		flag;

	i = -1;
	if (line[++i] != 'r')
		return (0);
	flag = 0;
	while (line[++i])
	{
		if (!ft_isdigit(line[i]))
			return (0);
		flag = 1;
	}
	res = register_nbr(line, i);
	return (res);
}

void		register_write(t_pack *da, int w)
{
	int		nbr;

	nbr = get_register(da->cmnds[da->l][w]);
	write(da->dsc, &nbr, 1);
}

void		pick_op_for_processing(t_pack *da, int w, int *idx)
{
	char	**arr;
	int		i;

	(*idx)++;
	i = -1;
	arr = da->cmnds[da->l];
	comm_info_to_file(da, idx);
	while (arr[++w])
	{
		i++;
		if (arr[w][0] == 'r' && register_check(arr[w]))
		{
			register_write(da, w);
		}
		else if (arr[w][0] == '%')
		{
			direct_write(da, w, i, idx);
		}
		else
		{
			indirect_case(da, w, i, idx);
		}
	}
}

void		go_through_ops(t_pack *da)
{
	int		k;

	da->l = -1;
	k = -1;
	while (da->cmnds[++da->l])
	{
		da->w = -1;
		while (da->cmnds[da->l][++da->w])
		{
			if (!da->w && compare_func(da->cmnds[da->l][da->w], da))
				pick_op_for_processing(da, da->w, &k);
			else if (!da->w && da->cmnds[da->l][da->w + 1] &&
			compare_func(da->cmnds[da->l][da->w + 1], da))
				pick_op_for_processing(da, da->w + 1, &k);
		}
	}
}
