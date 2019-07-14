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

// You must handle the validatoin of all the labels,
// populating array with the label`s names (using cycle of course)
// And only then going again through the tokens array and validating operations and labels
int         label_check(t_pack *data, int line)
{
    int		i;
    int		j;
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
		j = -1;
		while (data->labels[++j])
			;
		data->labels[j] = ft_strdup(buf); // Do not know what to do when the label already exists in the list
        ft_printf("Realoccing here for [%s]-i-[%d]-arr-[%s]\n", buf, j, data->labels[j]);
		ft_printf("check rest of the element\n");
		free(buf);
        return (1);
    }
	free(buf);
	if (data->tokens[line][0][i] == '#' && !i)	// if the comment is at the begining
		return (1);
	return (0);
}

int			op_after_label(t_pack *data, int line, int w)
{
	int		i;
	int		leng;
	char	*buf;

	buf = NULL;
	if (data->buf)
		buf = ft_strdup(data->buf);
	if (data->tokens[line][w])
	{
		i = -1;
		leng = 0;
		while (data->tokens[line][w][++i])
		{
			merge_chars(&buf, data->tokens[line][w][i]);
			leng = ft_strlen(buf);
			if (leng >= 2 && leng <= 5)
			{
				i = possible_ops(data, &buf, data->tokens[line][w], i);
				ft_printf("reading the operation [%p]\n", buf);
				if (i)
				{
					if (check_after_token(data, line, w, i))
					{
						ft_printf("Everything works fine\n");
						return (op_bridge(data, buf, line, w));	
					}
				}
				free(buf);
				return (0);
			}
		}
	}
	free(buf);
	return (1);
}

int         check_if_label(t_pack *data, int line)
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
		ft_printf("[%c]", data->tokens[line][0][i]);
		if (label_is_present(buf, data) && check_after_token(data, line, 0, i))
		{
			ft_printf("|\n");
			free(buf);
			ft_printf("activated\n");
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