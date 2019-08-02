/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_functions_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 11:40:48 by akorol            #+#    #+#             */
/*   Updated: 2019/07/14 11:41:01 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core_war.h"

int			backwards(char *line)
{
	int		b;
	int		i;

	b = 1;
	i = ft_strlen(line);
	while (i >= 0 && line[--i] && (line[i] == ' ' || line[i] == '\t'))
		;
	if (i >= 0 && line[i] != '\n')
		b = 0;
	free(line);
	return (b);
}

int			read_assm(t_pack *da)
{
	int		b;
	char	*line;
	char	*del;
	char	buf[BUF_SIZE + 1];

	b = 0;
	line = NULL;
	while ((b = read(da->dsc, buf, BUF_SIZE)))
	{
		buf[BUF_SIZE] = '\0';
		if (line)
		{
			del = line;
			line = ft_strjoin(del, buf);
			free(del);
		}
		else
			line = ft_strdup(buf);
	}
	return (backwards(line));
}
