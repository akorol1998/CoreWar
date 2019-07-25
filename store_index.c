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

// {"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25, "store index", 1, 1}

int				thrd_stage(t_pack *data, char **arr)
{
	int			res;

	res = 0;
	if (arr[2] && arr[2][0] == 'r' && register_check(arr[2]))
	{
		res = 1;
	}
	else if (arr[2][0] == '%')
	{
		if (arr[2][1] == ':' && direct_label(data, arr[2] + 2))
		{
			res = 1;
		}
		else if (direct_number(data, arr, 2))
		{
			res = 1;
		}
		else
			res = 0;
	}
	return (res);
}

int				scnd_stage(t_pack *data, char **arr)
{
	int			res;

	res = 0;
	if (arr[1] && arr[1][0] == 'r' && register_check(arr[1]))
		res = thrd_stage(data, arr);
	else if (arr[1][0] == '%')
	{
		if (arr[1][1] == ':' && direct_label(data, arr[1] + 2))
			res = thrd_stage(data, arr);
		else if (direct_number(data, arr, 1))
			res = thrd_stage(data, arr);
		else
			res = 0;
	}
	else if (indirect_validation(data, arr[1]) )
		res = thrd_stage(data, arr);
	else
		res = 0;
	return (res);
}

int				handle_sti(t_pack *data, char **arr)
{
	int			res;

	res = 0;
	if (arr[0] && arr[0][0] == 'r' && register_check(arr[0]))
		res = scnd_stage(data, arr);	
	else
		res = 0;
	if (res)
		args_to_cmnds(data, arr);
	return (res);
}
// 'w' is first argument
// int			register_sti(char **line, int w, int i)
// {
// 	char	*nbr;
// 	int		j;

// 	j = -1;
// 	nbr = ft_strsub(line[w], 1, i - 1);
// 	// free(line[w]);
// 	// line[w] = nbr;
// 	while(nbr[++j])
// 	{
// 		if (nbr[j] == '+' || nbr[j] == '-')
// 			return (0);
// 	}
// 	if (j > 2 || ft_atoi(nbr) > 99 || ft_atoi(nbr) < 0 ||
// 	ft_atoi(nbr) > REG_NUMBER)
// 	{
// 		free(nbr);
// 		return (0);
// 	}
// 	free(nbr);
// 	printf("Register [%s]\n", line[w]);
// 	return (1);
// }

// void		replace_array(t_pack *data, int line, int w, char **arr2d)
// {
// 	// char 	*fst;
// 	char	**barr;
// 	int		i;
// 	int		leng;

// 	i = -1;
// 	barr = (char**)malloc(sizeof(char) * w + 1);
// 	barr[w] = NULL;
// 	while (++i < w)
// 		barr[i] = ft_strdup(data->tokens[line][i]);
// 	i = -1;
// 	while (data->tokens[line][++i])
// 		free(data->tokens[line][i]);
// 	free(data->tokens[line]);
// 	leng = len_arr(arr2d) + 1;
// 	data->tokens[line] = (char**)malloc(sizeof(char*) * leng + 1);
// 	data->tokens[line][leng] = NULL;
// 	i = -1;
// 	while (++i < w)
// 		data->tokens[line][i] = barr[i];
// 	i = w - 1;
// 	while (++i < leng)
// 		data->tokens[line][i] = ft_strdup(arr2d[i - w]);
// 	free(barr);
// }

// void		create_coma_separated_array(t_pack *data, int line, int w)
// {
// 	char	*del;
// 	char	*arr;
// 	char	**arr2d;
// 	int		i;

// 	i = w;
// 	arr = ft_strdup(data->tokens[line][w]);
// 	while (data->tokens[line][++w])
// 	{
// 		del = arr;
// 		arr = ft_strjoin(arr, data->tokens[line][w]);
// 		free(del);
// 	}
// 	arr2d = ft_coma_hash_split(arr);
// 	free(arr);
	
// 	replace_array(data, line, i, arr2d);
// 	i = -1;
// 	while (arr2d[++i])
// 		free(arr2d[i]);
// 	free(arr2d);
// 	for(int k = 0;data->tokens[line][k];k++)
// 		ft_printf("hey efew [%s]\n", data->tokens[line][k]);
// }

// int			check_sti_op(t_pack *data, int line, int w)
// {
// 	char	*reg;
// 	int		i;
// 	int		res;

// 	reg = NULL;
// 	if (data->buf && ft_strcmp(data->buf, "sti"))
// 		return (0);
// 	create_coma_separated_array(data, line, w);
// 	if (!(data->tokens[line][w][0] == 'r'))
// 		return (0);
// 	merge_chars(&reg, data->tokens[line][w][0]);
// 	i = 0;
// 	while (data->tokens[line][w][++i])
// 	{
// 		if (!ft_isdigit(data->tokens[line][w][i]))
// 		{
// 			free(reg);
// 			return (0);
// 		}
// 	}
// 	free(reg);
// 	res = register_sti(data->tokens[line], w, i);
// 	res = res ? next_argument(data, data->tokens[line], w + 1) : 0;
// 	ft_printf("Next argument [%d]\n", res);
// 	return (res);
// }
