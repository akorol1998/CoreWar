/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_handle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 10:39:11 by akorol            #+#    #+#             */
/*   Updated: 2019/07/25 10:39:19 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core_war.h"

int			possible_ops(t_pack *data, char **buf, char *word, int i)
{
	int		n;
	char	*norm;

	n = -1;
	norm = NULL;
	while (compare_func(*buf, data))
	{
		n = i;
		if (word[++i])
		{
			if (norm)
				free(norm);
			norm = ft_strdup(*buf);
			merge_chars(buf, word[i]);
		}
		else
		{
			break ;
		}
	}
	if (norm && !compare_func(*buf, data))
	{
		free((*buf));
		(*buf) = ft_strdup(norm);
	}
	free(norm);
	return (n != -1 ? n : 0);
}

int			choose_operation(t_pack *data, char *op, char **arr)
{
	int		res;

	res = 0;
	if (!ft_strcmp(op, "live"))
	{
		data->arg_len = 1;
		if ((res = handle_live(data, arr)))
			res = check_line_tail(data, (arr)); //Custom index of where to start from
		ft_printf("Live\n");
	}
	if (!ft_strcmp(op, "ld"))
	{
		data->arg_len = 2;
		if ((res = handle_load(data, arr)))
			res = check_line_tail(data, (arr)); //Custom index of where to start from
		ft_printf("Load\n");
	}
	if (!ft_strcmp(op, "zjmp"))
	{
		data->arg_len = 1;
		if ((res = handle_live(data, arr)))
			res = check_line_tail(data, (arr)); //Custom index of where to start from
		ft_printf("ZJMP %d\n", res);
	}
	if (!ft_strcmp(op, "sti"))
	{
		data->arg_len = 3;
		if ((res = handle_sti(data, arr)))
			res = check_line_tail(data, (arr)); //Custom index of where to start from
		ft_printf("STI %d\n", res);
		for(int k=0; data->cmnds[data->l][k];k++)
			ft_printf(" %s", data->cmnds[data->l][k]);
	}
	if (!ft_strcmp(op, "add"))
	{
		data->arg_len = 3;
		if ((res = handle_add(data, arr)))
			res = check_line_tail(data, (arr)); //Custom index of where to start from
		ft_printf("ADD %d\n", res);
		for(int k=0; data->cmnds[data->l][k];k++)
			ft_printf(" %s", data->cmnds[data->l][k]);
	}
	if (!ft_strcmp(op, "sub"))
	{
		data->arg_len = 3;
		if ((res = handle_add(data, arr)))
			res = check_line_tail(data, (arr)); //Custom index of where to start from
		ft_printf("SUB %d\n", res);
		for(int k=0; data->cmnds[data->l][k];k++)
			ft_printf(" %s", data->cmnds[data->l][k]);
	}
	return (res);
}

int			check_line_tail(t_pack *data, char **arr)
{
	int		i;
	int		commment;

	i = -1;
	commment = 0;
	if (arr[data->arg_len] && arr[data->arg_len][0] != '#')
		return (0);
	return (1);
}

int			operation_valid(t_pack *data, char *op, char *line)
{
	char	**arr;
	int		res;
	int		i;

	res = 0;
	current_cmnds_position(data);
	data->cmnds[data->l][data->w] = ft_strdup(op);
	arr = coma_space_tab_split(line + ft_strlen(op));
	res = choose_operation(data, op, arr);
	i = -1;
	if (arr)
	{
		while (arr[++i])
		{
			free(arr[i]);
		}
		free(arr);
	}
	return (res);
}

int			handle_operation(t_pack *data, char *str)
{
	int		i;
	char	*op;
	char	*line;
	int		res;

	i = -1;
	op = NULL;
	while (str && (str[++i] == ' ' || str[i] == '\t'))
		;
	line = ft_strdup(str + i);
	if (!ft_strlen(line))
	{
		free(line);
		return (-1);
	}
	i = -1;
	while (ft_strlen(op) < 2 && line && line[++i])
		merge_chars(&op, line[i]);
	i = possible_ops(data, &op, line, i);
	if (i)
		res = operation_valid(data, op, line);
	else
		res = 0;
	free(line);
	free(op);
	return (res);
}
