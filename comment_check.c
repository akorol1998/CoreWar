/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comment_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 10:33:54 by akorol            #+#    #+#             */
/*   Updated: 2019/07/14 10:33:56 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core_war.h"

int			comment_check(t_pack *data, int line)
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
		i = -1;
		while (data->labels[++i])
			;
		data->labels[i] = ft_strdup(buf);
		free(buf);
        return (1);
    }
	free(buf);
	return (0);
}
