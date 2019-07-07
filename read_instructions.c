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

void		shift_pointers(char ***tokens, int j, int i)
{
	char	*ptr;
	char	**ptr2;
	int		leng;

	leng = -1;
	ptr = tokens[i][j];
	ptr2 = tokens[i];
	while (tokens[++leng])
		;
	while (i < leng)
	{
		tokens[i] = tokens[i + 1];
		i++;
	}
	free(ptr);
	free(ptr2);
}

// void		clean_from_spaces_tabs(t_pack *data)
// {
// 	int		i;

// 	i = -1;
// 	while (data->tokens[++i])
// 	{
// 		if (data->tokens[i][0])
// 		{
// 			ft_printf("line exists [%s]\n", data->tokens[i][0]);
// 		}
// 		if (data->tokens[i][0] && data->tokens[i][0][0] == '\n')
// 		{
// 			shift_pointers(data->tokens, 0, i);
// 			ft_printf("shifting [%d]\n", i);
// 		}
// 	}
// }

int			read_instructions(t_pack *data)
{
	char	*line;
	// char	**line_arr;
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
	// clean_from_spaces_tabs(data);
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
	// get_next_line(data->dsc, &line);
	// ft_printf("{%d} size - [%u]\n",ft_strlen(line_arr[0]), sizeof(line_arr[0]));
	system("leaks asm");
	exit(1);
	return (1);
}