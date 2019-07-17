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

int			valid_invalid_comment(char *buf)
{
	int		i;

	i = -1;
	while (buf[++i] && buf[i] != '#')
		;
	if (!buf[i])
		return (1);
	else if (buf[i] == '#' && !i)
		return (-1);
	else
		return (0);
}

int			label_is_present(char *lbl, t_pack *data)
{
	int		i;

	i = -1;
	while (data->labels[++i])
	{
		if (!ft_strcmp(data->labels[i], lbl))
			return (1);
	}
	return (0);
}

void		delete_commented_part_of_the_line(t_pack *data, int	line, int word)
{
	while (data->tokens[line][++word])
	{
		free(data->tokens[line][word]);
		data->tokens[line][word] = NULL;
	}
}

void		clean_line(char **line)
{
	int		i;

	i = -1;
	while (line[++i])
		free(line[i]);
	free(line);
}