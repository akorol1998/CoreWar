/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_commnets.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 12:11:33 by akorol            #+#    #+#             */
/*   Updated: 2019/07/17 12:36:59 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core_war.h"

void		shift_arr(t_pack *data, int line, int idx)
{
	int		i;

	ft_printf("hello hash %s\n", data->tokens[line][idx]);
	if (!data->tokens[line][idx] && !idx && line < data->file_lines)
	{
		i = line + 1;
		free(data->tokens[line]);
		while (data->tokens[i])
		{
			data->tokens[line] = data->tokens[i];
			line++;
			i++;
		}
		data->tokens[line] = data->tokens[i];
	}
}

void		line_without_comments(t_pack *data, int line, int w)
{
	int		i;
	char	*buf;

	i = -1;
	while (data->tokens[line][w][++i] && data->tokens[line][w][i] != '#')
		;
	buf = ft_strsub(data->tokens[line][w], 0, i);
	if (!ft_strlen(buf))
	{
		free(buf);
		buf = NULL;	
	}
	free(data->tokens[line][w]);
	data->tokens[line][w] = buf;
	ft_printf("Alright line = %d, word = %d, word = %s\n", line, w, data->tokens[line][w+1]);
	i = w;
	ft_printf("-___- [%s]\n", data->tokens[line][w+1]);
	while (data->tokens[line][++w])
	{
		// ft_printf("Deleting - %s\n", data->tokens[line][w]);
		free(data->tokens[line][w]);
		
		data->tokens[line][w] = NULL;
		// ft_printf("WORD [%d][%d] %s\n", line, w, data->tokens[6][0]);
	}
	shift_arr(data, line, i);
}

// void		delete_comments(t_pack *data)
// {
// 	int		i;
// 	int		j;
// 	int		k;
// 	int		x;

// 	i = -1;
// 	while (data->tokens[++i])
// 	{
		
// 		j = -1;
// 		x = 0;
// 		ft_printf("Line %d\n", i);
// 		while (data->tokens[i][++j])
// 		{
// 			k = -1;
// 			ft_printf("str %s\n", data->tokens[i][j]);
// 			while (data->tokens[i][j][++k])
// 			{
// 				ft_printf("char %c\n", data->tokens[i][j][k]);
// 				if (data->tokens[i][j][k] == '#')
// 				{
// 					line_without_comments(data, i, j);
// 					x = 1;
// 					break ;
// 				}
// 			}
// 			if (x)
// 				break ;
// 		}
// 	}
// }
