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

void         merge_chars(char **buf, char c)
{
    char    *del;
    char    *buf2;

    if (!(*buf))
    {
        (*buf) = ft_strnew(1);
        (*buf)[0] = c;
    }
    else
    {
        buf2 = ft_strnew(1);
        buf2[0] = c;
        del = (*buf);
        (*buf) = ft_strjoin((*buf), buf2);
        free(del);
        free(buf2);
    }
}

int         char_in_array(char c)
{
    int     i;

    i = -1;
    while (LABEL_CHARS[++i])
        if (LABEL_CHARS[i] == c)
            return (1);
    return (0);
}

int			check_after_token(t_pack *data, int line, int word, int i)
{
	// int		res;
	int		c;
	char	*buf;

	buf = NULL;
	c = 0;
	while (data->tokens[line][word][++i])
		merge_chars(&buf, data->tokens[line][word][i]);
	if (buf)
	{
		// if (!(res = valid_invalid_comment(buf)))
		// {
		// 	free(buf);
		// 	return (0);
		// }
		// if (res == -1)
		// 	delete_commented_part_of_the_line(data, line, word);
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
		ft_printf("BUF %s\n", data->buf);
		c = extract_op(data, 0);
		for(int u = 0;data->tokens[line][u];u++)
			ft_printf("<%s>", data->tokens[line][u]);
	}
	else if (data->tokens[line][word + 1])
	{
		c = extract_op(data, 1);
		for(int u = 0;data->tokens[line][u];u++)
			ft_printf("<%s>", data->tokens[line][u]);
	}
	return (c);
}
