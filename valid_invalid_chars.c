/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_invalid_chars.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 17:01:44 by akorol            #+#    #+#             */
/*   Updated: 2019/07/24 17:01:54 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core_war.h"

void		just_empty_line(t_pack *data, char *line)
{
	int		i;
	t_pack	*da;

	i = -1;
	da = data;
	while (line[++i] && (line[i] == '\t' || line[i] == ' '))
		;
	if (line[i] && line[i] != '#')
	{
		ft_printf("Unknown command [%s]\n", line);
		exit(1);
	}
}

void		clean_the_line(t_pack *data)
{
	int		i;

	i = -1;
	if (data->cmnds[data->l])
	{
		while (data->cmnds[data->l][++i])
		{
			free(data->cmnds[data->l][i]);
			data->cmnds[data->l][i] = NULL;
		}
	}
}

void		current_cmnds_position(t_pack *data)
{
	int		i;
	int		j;

	i = data->l;
	j = -1;
	while(data->cmnds[i] && data->cmnds[i][++j])
		;
	if (!data->cmnds[i])
	{
		data->cmnds[i] = (char**)malloc(sizeof(char*) * CHAMP_MAX_SIZE + 1);
		j = -1;
		while (++j <= CHAMP_MAX_SIZE )
			data->cmnds[i][j] = NULL;
		data->w = 0;
	}
	else
		data->w = j;
}

int			valid_invalid_chars(t_pack *data, char *line)
{
	int		idx;
	char	*str;
	int		res;

	str = NULL;
	res = 0;
	idx = read_labels(data, line);
	if (idx)
	{
		str = ft_strndup(line, idx);
		current_cmnds_position(data);
		data->cmnds[data->l][data->w] = ft_strdup(str);
		res = handle_operation(data, line + ft_strlen(str));
		free(str);
	}
	else if (is_operation(data, line))
		res = 1;
	else
		return (res);
	return (res);
}