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

int			actual_instructions(t_pack *data)
{
	int		line;

	line = -1;
	while (data->tokens[++line])
	{
		if (!label_check(data, line))
			ft_printf("WEll it is really weird error\n");
	}
	line = -1;
	while (data->tokens[++line])
	{
		if (!check_if_label(data, line))
		{
			ft_printf("The first element ======= %s ======\n", data->tokens[line][0]);
			if (!check_for_being_op(data, line))
				ft_printf("Some shit, i don't know\n");
		}
	}
	for(int i=0;data->labels[i];i++)
	{
		ft_printf("LBL [%s]\n", data->labels[i]);
	}
	
	return (1);
}


int			read_instructions(t_pack *data)
{
	char	*line;
	int		i;

	if (!(data->tokens = (char***)malloc(sizeof(char**) * CHAMP_MAX_SIZE + 1)))
		return (0); //free structure and exit the program
	data->tokens[CHAMP_MAX_SIZE] = NULL;
	i = -1;
	while (get_next_line(data->dsc, &line) && ++i < CHAMP_MAX_SIZE)
	{
		data->tokens[i] = ft_space_tab_split(line);
		if (!data->tokens[i])
			i--;
		free(line);
		data->file_lines++;
	}
	
	delete_comments(data);
	print_tokens(data);
	actual_instructions(data);
	return (1);
}