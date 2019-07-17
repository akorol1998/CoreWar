/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 12:57:19 by akorol            #+#    #+#             */
/*   Updated: 2019/07/17 12:57:29 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core_war.h"

char 		**squeeze_elements(t_pack *data)
{
	int		i;
	char	**tab;

	i = -1;
	while (data->tokens[data->line][++i] && i <= data->w)
		;
	tab = (char **)malloc(sizeof(char *) * i + 1);
	tab[i] = NULL;
	i = -1;
	while (data->tokens[data->line][++i] && i <= data->w)
		tab[i] = ft_strdup(data->tokens[data->line][i]);
	return (tab);
}

void		replace_elements_in_line(t_pack *data, char **arr, char **arr2)
{
	int		i;
	int		j;
	int		len;
	int		len2;

	i = -1;
	while (data->tokens[data->line][++i])
		free(data->tokens[data->line][i]);
	free(data->tokens[data->line]);
	data->tokens[data->line] = NULL;
	len = len_arr(arr);
	len2 = len_arr(arr2);
	data->tokens[data->line] = (char**)malloc(sizeof(char*) * (len + len2) + 1);
	data->tokens[data->line][len + len2] = NULL;
	i = -1;
	while (++i < len)
		data->tokens[data->line][i] = arr[i];
	j = i;
	i = -1;
	while (++i + j < len + len2)
		data->tokens[data->line][i + j] = arr2[i];
	free(arr);
	free(arr2);
}	

int			replace_elements(t_pack *data, char *arg)
{
	char	*buf;
	char	**arr2;
	char	**arr;
	int		i;

	data->w--;
	buf = ft_strsub(data->tokens[data->line][data->w], 0, ft_strlen(arg));
	free(data->tokens[data->line][data->w]);
	data->tokens[data->line][data->w] = buf;
	i = data->w;
	while (data->tokens[data->line][++i])
	{
		if (data->buf)
		{
			if (data->buf[0] != '0')
				return (0);
			buf = data->buf;
			data->buf = ft_strjoin(buf, data->tokens[data->line][i]);
			free(buf);
		}
		else
		{
			data->buf = ft_strdup(data->tokens[data->line][i]);
		}
	}
	arr2 = ft_strsplit(data->buf, ',');
	arr = squeeze_elements(data);
	replace_elements_in_line(data, arr, arr2);
	return (1);
}

int			check_indirect_arg(t_pack *data)
{
	data = NULL;
	return (1);
}

int			check_2nd_arg(t_pack *data)
{
	char 	**str;
	int		w;

	w = data->w++;
	str = data->tokens[data->line];
	if (str[w][0] == 'r' && register_check(str, w))
		return (1);
	return (0);
}

int			read_ld_args(t_pack *data)
{
	int		res;

	res = 0;
	ft_printf("------%s\n", data->tokens[data->line][data->w]);
	if (data->tokens[data->line][data->w][0] == '%')
	{
		if (data->tokens[data->line][data->w][1] == ':'
		&& direct_label(data, data->tokens[data->line], 1, 2))
		{
			check_2nd_arg(data);
			ft_printf("Direct label res [%d]\n", res);
		}
		else if (direct_number(data, data->tokens[data->line], data->w, 2))
		{
			check_2nd_arg(data);
			ft_printf("Direct Number res [%d]\n", res);
		}
		else
			ft_printf("Wrong moves\n");
		for(int k = 0; data->tokens[data->line][k];k++)
			ft_printf("==%s==\n", data->tokens[data->line][k]);
	}
	else if (check_indirect_arg(data))
	{
		check_2nd_arg(data);
		ft_printf("do some stuff\n");
	}
	else
	{
		ft_printf("wrong instruciton!\n");
	}
	
	return (res);
}

int			check_ld_op(t_pack *data, char *buf)
{
	int		res;

	res = 0;
	// if (data->buf)
	// {
	res = replace_elements(data, buf);
	data->w++;
	read_ld_args(data);
	// }
	system("leaks asm");
	exit(1);
	return (1);
}