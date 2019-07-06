/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 16:41:24 by akorol            #+#    #+#             */
/*   Updated: 2019/03/19 16:41:28 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			separation_vol2(char const *str, int *min, int len)
{
	int			i;
	int			j;
	char		*dig;

	dig = NULL;
	i = -1;
	while (++i < len)
	{
		j = 0;
		while (ft_isdigit(str[i + j]) && (str[i + j] != '0'
			|| ft_isdigit(str[i + j - 1])))
		{
			++j;
			if (!ft_isdigit(str[i + j]))
			{
				dig = ft_strsub(str, i, j);
				*min = ft_atoi(dig);
				free(dig);
			}
		}
		i += j;
	}
}

int				separation(char const *str, int len)
{
	int			min;

	min = 0;
	separation_vol2(str, &min, len);
	return (min);
}

int				separation_vol3(char const *str, t_nigga **nig)
{
	int			i;
	int			j;
	int			min;
	char		*trash;

	min = 0;
	i = 0;
	while (str && str[i] && str[i] != *(*nig)->conv)
	{
		j = 0;
		while (str[i + j] && ft_isdigit(str[i + j]) &&
			(str[i + j] != '0' || ft_isdigit(str[i + j - 1])))
		{
			++j;
			if (!ft_isdigit(str[i + j]))
			{
				trash = ft_strsub(str, i, j);
				min = ft_atoi(trash);
				free(trash);
			}
		}
		i += j > 0 ? j : 1;
	}
	return (min);
}

char			*fill_for_c(t_nigga **nig)
{
	int			size;
	char		*tab;
	int			i;

	size = (*nig)->m_s;
	tab = ft_strnew(size);
	i = -1;
	if ((*nig)->zero && !(*nig)->minus)
	{
		while (++i < size)
			tab[i] = '0';
	}
	else
	{
		while (++i < size)
			tab[i] = ' ';
	}
	return (tab);
}

char			*process_piece_c(char const *str, t_nigga **nig)
{
	char		*area;

	area = ft_strsub(str, 0, (*nig)->conv - str);
	check_min_width(area, nig);
	free(area);
	area = fill_for_c(nig);
	return (area);
}
