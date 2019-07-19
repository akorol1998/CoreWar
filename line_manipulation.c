/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_manipulation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 14:30:36 by akorol            #+#    #+#             */
/*   Updated: 2019/07/19 14:30:44 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core_war.h"

int		arrcnp(char	**arr1, char **arr2, int s)
{
	int		i;

	i = -1;
	if (!arr1 || !arr2)
		return (0);
	while (arr1[++i] && arr2[s])
	{
		arr1[i] = arr2[s];
		s++;
	}
	return (1);
}

int			new_line_func(t_pack *data, char *buf)
{
	char	*fst;
	char	**arr1;
	char	**arr2;
	int		len;
	int		i;

	len = 0;
	fst = ft_strsub(data->tokens[data->line][0], 0,
	ft_strlen(data->tokens[data->line][0]) - ft_strlen(buf));
	arr1 = (char**)malloc(sizeof(char*) * 3);
	arr1[2] = NULL;
	arr1[0] = fst;
	arr1[1] = ft_strdup(buf);
	i = data->w;
	while (data->tokens[data->line][i])
	{
		ft_printf("(%s)\n", data->tokens[data->line][i]);
		i++;
	}
	ft_printf("w - %d, i - %d\n", data->w, i);
	len = i - data->w;
	arr2 = (char**)malloc(sizeof(char*) * len + 1);
	arr2[len] = NULL;
	ft_printf("The length {%d}  - %s\n", len, data->tokens[data->line][data->w]);
	if (arrcnp(arr2, data->tokens[data->line], data->w))
	{
		for(int k = 0; arr1[k];k++)
			ft_printf("arr1 %s\n", arr1[k]);
		for(int k = 0; arr2[k];k++)
			ft_printf("arr2 %s\n", arr2[k]);
	}
	return (1);
}
