/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buf_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 16:51:10 by akorol            #+#    #+#             */
/*   Updated: 2019/07/18 16:51:29 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core_war.h"

void		label_case(t_pack *data, char **tab)
{
	char	**temp;
	char	**arr;
	int		ln;
	int		j;
	int		i;

	temp = (char**)malloc(sizeof(char*) * 3);
	temp[2] = NULL;
	temp[0] = ft_strdup(data->cmnds[data->l][0]);
	temp[1] = ft_strdup(data->cmnds[data->l][1]);
	ln = len_arr(temp) + len_arr(tab);
	arr = (char**)malloc(sizeof(char*) * ln + 1);
	arr[ln] = NULL;
	i = -1;
	while (temp[++i])
		arr[i] = temp[i];
	j = -1;
	while (tab[++j])
		arr[i + j] = tab[j];
	free(tab);
	free(temp);
	i = -1;
	while (data->cmnds[data->l][++i])
		free(data->cmnds[data->l][i]);
	free(data->cmnds[data->l]);
	data->cmnds[data->l] = arr;
}

void		final_cut(t_pack *data, char **tab)
{
	int		i;

	if(data->lbl)
		label_case(data, tab);
	else
	{
		for (int k = 0;data->cmnds[data->l][k];k++)
			ft_printf("tokens -- %s\n", data->cmnds[data->l][k]);
		for (int k = 0;tab[k];k++)
			ft_printf("Tab -- %s\n", tab[k]);
		structurize(data);
		i = -1;
		while (tab[++i])
			free(tab[i]);
		free(tab);
	}
}

int			validate_ld_args(t_pack *data, char **tab)
{
	int		res;

	if (data->arg1 && data->arg2)
		res = 1;
	else if (!data->arg1)
		res = 0;
	if (!data->arg2)
		res = register_check(tab, 1);
	else
		res = 1;
	if (res)
	{
		final_cut(data, tab);
	}
	return (res);
}

int			merge_arrays(t_pack *data, char **arr1, char **arr2)
{
	int		ln;
	int		j;
	int		i;
	char	**tab;

	ln = len_arr(arr1) + len_arr(arr2);
	tab = (char**)malloc(sizeof(char*) * ln + 1);
	tab[ln] = NULL;
	i = -1;
	while (arr1[++i])
		tab[i] = arr1[i];
	j = -1;
	while (arr2[++j])
		tab[j + i] = arr2[j];
	return (validate_ld_args(data, tab));
}

int			concatenate_buf(t_pack *data)
{
	char	**arr1;
	char	**arr2;
	char	*buf;
	char	*del;
	int		i;

	i = ++data->w;
	arr1 = ft_strsplit(data->buf, ',');
	buf = NULL;
	if (data->cmnds[data->l][data->w])
	{
		buf = ft_strdup(data->cmnds[data->l][data->w]);
		while (data->cmnds[data->l][++i])
		{
			del = buf;
			buf = ft_strjoin(buf, data->cmnds[data->l][i]);
			free(del);
		}
		arr2 = ft_strsplit(buf, ',');
		free(buf);
		ft_printf("(((((\n");
		i = merge_arrays(data, arr1, arr2);
		free(arr2);
		free(arr1);
	}
	else
	{
		i = validate_ld_args(data, arr1);
	}
	return (i);
}

int			buf_manager(t_pack *data, char *fst)
{
	char	**arr;
	int		res;
	int		i;

	arr = ft_strsplit(data->buf, ',');
	data->w = 0;
	//Custom function
	res = read_ld_args(data, arr);
	ft_printf("arg1 - 1[%d] arg2 - 2[%d] arg3 - 3[%d]\n", data->arg1, data->arg2, data->arg3);
	fst = NULL;
	i = -1;
	while (arr[++i])
		free(arr[i]);
	free(arr);
	return (res);
}