/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 10:34:06 by akorol            #+#    #+#             */
/*   Updated: 2019/07/14 10:34:08 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core_war.h"

int			no_label(char *buf, t_pack *data)
{
	int		i;

	i = -1;
	while(data->labels[++i])
	{
		if (!ft_strcmp(buf, data->labels[i]))
			return (0);
	}
	data->labels[i] = ft_strdup(buf);
	return (1);
}

int         label_check(t_pack *data, int line)
{
    int		i;
    char    *buf;

    buf = NULL;
	i = -1;
	if(data->tokens[line])
	{
		while (data->tokens[line][0] && data->tokens[line][0][++i] && 
        char_in_array(data->tokens[line][0][i]) &&
        data->tokens[line][0][i] != LABEL_CHAR)
			merge_chars(&buf, data->tokens[line][0][i]);
		ft_printf("before break [%d]-[%d]\n", line, i);
		if (i != -1 && data->tokens[line][0][i] == LABEL_CHAR)
		{
			merge_chars(&buf, data->tokens[line][0][i]);
			i = no_label(buf, data);
			free(buf);
			return (i);
		}
		ft_printf("before break [%d]-[%d]\n", line, i);
		free(buf);
	}
	
	// if (data->tokens[line][0][i] == '#' && !i)	// if the comment is at the begining
	// 	return (1);
	return (0);
}

int			op_after_label(t_pack *data, int line, int w)
{
	int		i;
	int		leng;
	char	*buf;

	buf = NULL;
	if (data->tokens[line][w])
	{
		buf = ft_strdup(data->tokens[line][w]);
		leng = 0;
		i = 0;
		if ((leng = ft_strlen(buf)) >= 2 && leng <= 5)
		{
			i = compare_func(buf, data);
			// i = possible_ops(data, &buf, data->tokens[line][w], i);
			if (i)
			{
				data->w = 2;
				i = op_bridge(data, buf, line, w);
				free(buf);
				return (i);
			}
			free(buf);
			return (0);
		}
	}
	free(buf);
	return (1);
}

int         check_if_label(t_pack *data, int line) //What to do when separate lines
{
    int		i;
    char    *buf;

    buf = NULL;
	i = -1;
	if(data->tokens[line])
	{
		while (data->tokens[line][0] && data->tokens[line][0][++i] && 
        char_in_array(data->tokens[line][0][i]) &&
        data->tokens[line][0][i] != LABEL_CHAR)
			merge_chars(&buf, data->tokens[line][0][i]);
	}
	if (data->tokens[line][0][i] == LABEL_CHAR)
	{
		merge_chars(&buf, data->tokens[line][0][i]);
		ft_printf(".....................[%s]....................\n", buf);
		if (label_is_present(buf, data) && check_after_token(data, line, 0, i))
		{
			free(buf);
			for(int k = 0;data->tokens[line][k];k++)
				ft_printf("|%s|", data->tokens[line][k]);
			ft_printf("\n");
			return (op_after_label(data, line, 1));
		}
		free(buf);
		return (0);
	}
	free(buf);
	if (data->tokens[line][0][i] == '#' && !i)	// if the comment is at the begining
		return (1);
	return (0);
}