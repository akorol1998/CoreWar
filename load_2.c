/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 12:39:08 by akorol            #+#    #+#             */
/*   Updated: 2019/07/18 12:39:19 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core_war.h"

void		label_yes(t_pack *data, char ***arr1, char ***arr2)
{
	char	*buf;
	char	*del;
	int		i;

	(*arr1) = (char**)malloc(sizeof(char*) * 3);
	(*arr1)[2] = NULL;
	(*arr1)[0] = ft_strdup(data->tokens[data->line][0]);
	(*arr1)[1] = ft_strdup(data->tokens[data->line][1]);
	buf = NULL;
	i = 2;
	buf = ft_strdup(data->tokens[data->line][i]);
	while (data->tokens[data->line][++i])
	{
		del = buf;
		buf = ft_strjoin(buf, data->tokens[data->line][i]);
		free(del);
	}
	(*arr2) = ft_strsplit(buf, ',');
	free(buf);
}

void		label_no(t_pack *data, char ***arr1, char ***arr2)
{
	char	*buf;
	char	*del;
	int		i;

	(*arr1) = (char**)malloc(sizeof(char*) * 2);
	(*arr1)[1] = NULL;
	(*arr1)[0] = ft_strdup(data->tokens[data->line][0]);
	buf = NULL;
	i = 1;
	buf = ft_strdup(data->tokens[data->line][i]);
	while (data->tokens[data->line][++i])
	{
		del = buf;
		buf = ft_strjoin(buf, data->tokens[data->line][i]);
		free(del);
	}
	(*arr2) = ft_strsplit(buf, ',');
	free(buf);
}


void		structurize(t_pack *data)
{
	char	**arr1;
	char	**arr2;

	arr1 = NULL;
	arr2 = NULL;
	if (data->lbl)
	{
		label_yes(data, &arr1, &arr2);
	}
	else
	{
		label_no(data, &arr1, &arr2);
	}
	replace_elements_in_line(data, arr1, arr2);
}