/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_index.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 10:35:10 by akorol            #+#    #+#             */
/*   Updated: 2019/07/14 10:35:11 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core_war.h"

// {"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
// 		"store index", 1, 1}

// 'w' is first argument
int			register_sti(char **line, int w, int i)
{
	char	*nbr;

	nbr = ft_strsub(line[w], 1, i - 1);
	free(line[w]);
	line[w] = nbr;
	printf("first register [%s]\n", line[w]);
	return (1);
}

void		replace_array(t_pack *data, int line, char **arr2d)
{
	char 	*fst;
	int		i;
	int		leng;

	fst = ft_strdup(data->tokens[line][0]);
	i = -1;
	while (data->tokens[line][++i])
		free(data->tokens[line][i]);
	free(data->tokens[line]);
	leng = len_arr(arr2d) + 1;
	data->tokens[line] = (char**)malloc(sizeof(char*) * leng + 1);
	data->tokens[line][leng] = NULL;
	data->tokens[line][0] = fst;
	i = 0;
	while (data->tokens[line][++i])
		data->tokens[line][i] = arr2d[i - 1];
}

void		create_coma_separated_array(t_pack *data, int line, int w)
{
	char	*del;
	char	*arr;
	char	**arr2d;
	int		i;

	i = w;
	arr = ft_strdup(data->tokens[line][w]);
	while (data->tokens[line][++w])
	{
		del = arr;
		arr = ft_strjoin(arr, data->tokens[line][w]);
		free(del);
	}
	arr2d = ft_strsplit(arr, ',');
	free(arr);
	replace_array(data, line, arr2d);
	free(arr2d);
	for(int k = 0;data->tokens[line][k];k++)
		ft_printf("hey efew [%s]\n", data->tokens[line][k]);	
}

int			check_sti_op(t_pack *data, int line, int w)
{
	char	*reg;
	int		i;
	int		res;

	reg = NULL;
	create_coma_separated_array(data, line, w);
	if (!(data->tokens[line][w][0] == 'r'))
		return (0);
	merge_chars(&reg, data->tokens[line][w][0]);
	i = 0;
	while (data->tokens[line][w][++i])
	{
		if (!ft_isdigit(data->tokens[line][w][i]))
		{
			free(reg);
			return (0);
		}
	}
	res = register_sti(data->tokens[line], w, i);
	res = res ? next_argument(data, data->tokens[line], w + 1) : 0;
	free(reg);
	return (res);
}
