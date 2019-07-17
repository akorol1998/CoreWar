/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_commnets.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 12:11:33 by akorol            #+#    #+#             */
/*   Updated: 2019/07/17 12:36:59 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core_war.h"

void		line_without_comments(t_pack *data, int line, int w)
{
	int		i;
	char	*buf;

	i = -1;
	while (data->tokens[line][w][++i] && data->tokens[line][w][i] != '#')
		;
	buf = ft_strsub(data->tokens[line][w], 0, i);
	free(data->tokens[line][w]);
	data->tokens[line][w] = buf;
	while (data->tokens[line][++w])
	{
		ft_printf("deleting %s\n", data->tokens[line][w]);
		free(data->tokens[line][w]);
		data->tokens[line][w] = NULL;
	}
}

void		delete_comments(t_pack *data)
{
	int		i;
	int		j;
	int		k;
	int		x;

	i = -1;
	while (data->tokens[++i])
	{
		j = -1;
		x = 0;
		while (data->tokens[i][++j])
		{
			k = -1;
			while (data->tokens[i][j][++k])
			{
				if (data->tokens[i][j][k] == '#')
				{
					line_without_comments(data, i, j);
					x = 1;
					break ;
				}
			}
			if (x)
				break ;
		}
	}
}
