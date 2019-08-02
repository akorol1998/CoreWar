/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_direct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 11:27:28 by akorol            #+#    #+#             */
/*   Updated: 2019/07/31 11:27:44 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core_war.h"

char		*get_direct_label(t_pack *data, char *line)
{
	int		i;
	char	*del;

	del = ft_strjoin(line, ":");
	i = -1;
	while (data->labels[++i])
	{
		if (!ft_strcmp(data->labels[i], del))
		{
			return (del);
		}
	}
	free(del);
	return (NULL);
}

int				search_for_label_down(t_pack *da, int *idx, char *lbl)
{
	int			l;
	int			k;
	int			size;

	l = da->l;
	k = *idx;
	size = 0;
	while (da->cmnds[++l] && da->comm[k] >= 0)
	{
		if (!ft_strcmp(da->cmnds[l][0], lbl))
		{
			size += da->comm[k]->size;
			k++;
			return (size);
		}
		else if ((da->cmnds[l][0] && compare_func(da->cmnds[l][0], da))
		|| (da->cmnds[l][1] && compare_func(da->cmnds[l][1], da)))
		{
			size += da->comm[k]->size;
			k++;
		}
	}
	return (-1);
}

int				search_for_label(t_pack *da, int *idx, char *lbl)
{
	int			l;
	int			k;
	int			size;

	l = da->l;
	k = *idx;
	size = 0;
	if (!ft_strcmp(da->cmnds[l][0], lbl))
		return (size);
	if (!ft_strcmp(lbl, "live:"))
		ft_printf("Live - Line %d, index - %d\n", l, k);
	while (--l >= 0 && k >= 0)
	{
		if (!ft_strcmp(da->cmnds[l][0], lbl))
		{
			if (da->cmnds[l][1] && compare_func(da->cmnds[l][1], da))
			{
				k--;
				size += da->comm[k]->size;
			}
			return (-size);
		}
		else if ((da->cmnds[l][0] && compare_func(da->cmnds[l][0], da))
		|| (da->cmnds[l][1] && compare_func(da->cmnds[l][1], da)))
		{
			k--;
			size += da->comm[k]->size;
		}
	}
	size = search_for_label_down(da, idx, lbl);
	return (size);
}

void			write_to_file(t_pack *da, int size, int nbr)
{
	int			t;
	int			a;
	
	t = size - 1;
	// ft_printf(" NUmber %d [", nbr);
	while (t >= 0)
	{
		a = nbr >> 8 * t;
		// ft_printf(" %d-%x ", a);
		write(da->dsc, &a, 1);
		t--;
	}
	// ft_printf("]\n");
}

void			direct_write(t_pack *da, int w, int	i, int *idx)
{
	int			size;
	int			nbr;
	char		*lbl;

	lbl = NULL;
	if (!i)
		size = da->comm[*idx]->arg1;
	else if (i == 1)
		size = da->comm[*idx]->arg2;
	else if (i == 2)
		size = da->comm[*idx]->arg3;
	if (da->cmnds[da->l][w][1] == ':' &&
	(lbl = get_direct_label(da, da->cmnds[da->l][w] + 2)))
	{
		nbr = search_for_label(da, idx, lbl);
		write_to_file(da, size, nbr);
	}
	else
	{
		nbr = get_direct_number(da, da->cmnds[da->l], w);
		write_to_file(da, size, nbr);
	}
	free(lbl);
}
