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

void		current_cmnds_position(t_pack *data)
{
	int		i;
	int		j;

	i = data->line;
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

	str = NULL;
	idx = read_labels(data, line); // If fst element is Label
	if (idx)
	{
		str = ft_strndup(line, idx);
		current_cmnds_position(data);
		data->cmnds[data->line][data->w] = str;
		ft_printf("line - %d, w - %d\n", data->line, data->w);
		system("leaks asm");
		exit(1);
	}
	// else if () // Check if operation
	return (1);
}