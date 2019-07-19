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

// void		label_line(t_pack *data, char **tab)
// {
	
// }

void		no_label_line(t_pack *data, char **tab)
{
	char	*fst;
	int		i;
	int		ln;

	fst = ft_strsub(data->tokens[data->line][0], 0,
	ft_strlen(data->tokens[data->line][0]) - ft_strlen(tab[0]));
	i = -1;
	while (data->tokens[data->line][++i])
		free(data->tokens[data->line][i]);
	free(data->tokens[data->line]);
	ln = len_arr(tab) + 1;
	data->tokens[data->line] = (char**)malloc(sizeof(char*) * ln + 1);
	data->tokens[data->line][ln] = NULL;
	i = -1;
	data->tokens[data->line][++i] = fst;
	while (++i < ln)
		data->tokens[data->line][i] = tab[i - 1];
	free(tab);
}

void		create_new_line(t_pack *data, char **tab)
{
	if (data->lbl)
	{
		;
		// label_line(data, tab); Basically if we got label, program should replace not 0 index but 1 index element
	}
	else
	{
		no_label_line(data, tab);
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
		create_new_line(data, tab);
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

	i = data->w;
	arr1 = ft_strsplit(data->buf, ',');
	if (data->tokens[data->line][data->w])
	{
		buf = ft_strdup(data->tokens[data->line][data->w]);
		while (data->tokens[data->line][++i])
		{
			del = buf;
			buf = ft_strjoin(del, data->tokens[data->line][i]);
			free(del);
		}
		arr2 = ft_strsplit(buf, ',');
		i = merge_arrays(data, arr1, arr2);
		free(arr2);
	}
	else
		i = validate_ld_args(data, arr1);
	free(arr1);
	return (i);
}

int			buf_manager(t_pack *data, char *fst)
{
	char	**arr;
	int		res;
	int		i;

	arr = ft_strsplit(data->buf, ',');
	data->w = 0;
	res = read_ld_args(data, arr);
	ft_printf("arg1 - 1[%d] arg2 - 2[%d] arg3 - 3[%d]\n", data->arg1, data->arg2, data->arg3);
	fst = NULL;
	i = -1;
	while (arr[++i])
		free(arr[i]);
	free(arr);
	return (res);
}