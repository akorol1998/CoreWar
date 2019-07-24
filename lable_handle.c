/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 14:34:29 by akorol            #+#    #+#             */
/*   Updated: 2019/07/24 14:35:50 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core_war.h"

int         char_in_array(char c)
{
    int     i;

    i = -1;
    while (LABEL_CHARS[++i])
        if (LABEL_CHARS[i] == c)
            return (1);
    return (0);
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
