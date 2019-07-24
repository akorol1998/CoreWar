/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 10:36:44 by akorol            #+#    #+#             */
/*   Updated: 2019/07/14 10:36:45 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core_war.h"

int			len_arr(char **arr)
{
	int		i;

	i = -1;
	while (arr[++i])
		;
	return (i);
}

int			compare_func(char *buf, t_pack *data)
{
	int		i;
	int		j;

	i = -1;
	j = ft_strlen(buf);
	while (data->op[++i])
	{
		if (!ft_strncmp(data->op[i], buf, j))
			return (1); // changed 0
	}
	return (0); // changed 1
}

int			check_after_token(t_pack *data, int line, int word, int i)
{
	// int		res;
	int		c;
	char	*buf;

	buf = NULL;
	c = 0;
	ft_printf("TTTTT - %s [%d][%d][%d]\n", data->tokens[line][word], line, word, i);
	while (data->tokens[line][word][++i])
		merge_chars(&buf, data->tokens[line][word][i]);
	if (buf)
	{
		if (!data->buf)
			data->buf = buf;
		else
		{
			free(data->buf);
			data->buf = buf;
		}
		new_line_func(data, data->buf, line);
		if (!data->lbl)
			return (1);
		ft_printf("AFTER\n");
		for(int u = 0;data->tokens[line][u];u++)
			ft_printf("<%s>", data->tokens[line][u]);
		data->op_idx = 1;
		c = extract_op(data);
		for(int u = 0;data->tokens[line][u];u++)
			ft_printf("<%s>", data->tokens[line][u]);
	}
	else if (data->tokens[line][word + 1])
	{
		for(int u = 0;data->tokens[line][u];u++)
			ft_printf("<%s>", data->tokens[line][u]);
		data->w = !data->buf && data->lbl ? 1 : 0;
		c = extract_op(data);
		for(int u = 0;data->tokens[line][u];u++)
			ft_printf("<%s>", data->tokens[line][u]);
	}
	return (c);
}
