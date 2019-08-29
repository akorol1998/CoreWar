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

int				search_for_label_2(t_pack *da, char *lbl, int l, int k)
{
	int			size;
	int			buf;

	size = -1;
	buf = 0;
	while (--l >= 0 && k >= 0)
	{
		if (!ft_strcmp(da->cmnds[l][0], lbl))
		{
			if (da->cmnds[l][1] && compare_func(da->cmnds[l][1], da))
			{
				k--;
				buf += da->comm[k]->size;
			}
			size = buf;
		}
		else if ((da->cmnds[l][0] && compare_func(da->cmnds[l][0], da))
		|| (da->cmnds[l][1] && compare_func(da->cmnds[l][1], da)))
		{
			k--;
			buf += da->comm[k]->size;
		}
	}
	return (size);
}

int				search_for_label(t_pack *da, int *idx, char *lbl)
{
	int			l;
	int			k;
	int			size;

	l = da->l;
	k = *idx;
	size = -1;
	if (!ft_strcmp(da->cmnds[l][0], lbl))
		return (0);
	size = search_for_label_2(da, lbl, l, k);
	if (size != -1)
		return (-size);
	size = search_for_label_down(da, idx, lbl);
	return (size);
}

void			write_to_file(t_pack *da, int size, int nbr)
{
	int			t;
	int			a;

	t = size - 1;
	while (t >= 0)
	{
		a = nbr >> 8 * t;
		write(da->dsc, &a, 1);
		t--;
	}
}

void			direct_write(t_pack *da, int w, int i, int *idx)
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
