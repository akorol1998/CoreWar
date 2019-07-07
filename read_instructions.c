/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 13:41:15 by akorol            #+#    #+#             */
/*   Updated: 2019/07/07 13:41:24 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core_war.h"

int			read_instructions(t_pack *data)
{
	char	*line;
	int		i;
	int		j;

	if (!(data->tokens = (char***)malloc(sizeof(char**) * (MEM_SIZE / 6) + 1)))
		return (0); //free structure and exit the program
	data->tokens[(MEM_SIZE / 6)] = NULL;
	i = -1;
	while (get_next_line(data->dsc, &line) && ++i < (MEM_SIZE / 6))
	{
		data->tokens[i] = ft_space_tab_split(line);
		if (!data->tokens[i][0])
		{
			free(data->tokens[i]);
			i--;
		}
		free(line);
	}
	i = -1;
	j = -1;
	while (data->tokens[++i])
	{
		j = -1;
		while (data->tokens[i][++j])
		{
			printf("%s ", data->tokens[i][j]);
		}
		printf("\n");
	}
	system("leaks asm");
	exit(1);
	return (1);
}