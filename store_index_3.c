/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_index_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 11:02:34 by akorol            #+#    #+#             */
/*   Updated: 2019/07/18 11:02:42 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core_war.h"

int			indirect_validation(t_pack *data, char **line, int w)
{
	char	*nbr;
	int		res;
	int		i;

	i = -1;
	res = 0;
	if (line[w] && line[w][0] == ':' && direct_label(data, line, 0, 1))
		return (1);
	else
	{
		while(line[w][++i])
		{
			if (line[w][i] == '+' || (!ft_isdigit(line[w][i]) && i))
				return (0);
		}
		nbr = ft_strdup(line[w]);
		res = ft_atoi(nbr) ? 1 : 0;
		free(nbr);
		return (res ? res : 0);
	}
}

int			third_argument(t_pack *data, char **line, int w)
{
	if (line[w][0] == 'r' && register_check(line, w))
		return (1);
	else if (line[w][0] == '%')
	{
		if (line[w][1] == ':' && direct_label(data, line, w, 2))
			return (1);
		else if (direct_number(data, line, w))
			return (1);
		return (0);
	}
	return (0);
}

int			indirect_arg(t_pack *data, char **line, int w)
{
	char 	*nbr;
	int		i;

	i = -1;
	while (line[w][++i])
	{
		if (line[w][i] == '+')
			return (0);
	}
	nbr = ft_strsub(line[w], 0, i);
	i = ft_atoi(nbr);
	free(nbr);
	data = NULL;
	return (i);
}