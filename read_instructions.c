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

// int			actual_instructions(t_pack *data)
// {
// 	data->line = -1;
// 	while (data->tokens[++data->line])
// 	{
// 		if (!label_check(data, data->line))
// 			ft_printf("WEll it is really weird error\n");
// 	}
// 	data->line = -1;
// 	while (data->tokens[++data->line])
// 	{
// 		if (!check_if_label(data, data->line))
// 		{
// 			ft_printf("The first element ======= %s ======\n", data->tokens[data->line][0]);
// 			if (!check_for_being_op(data, data->line))
// 				ft_printf("Some shit, i don't know\n");
// 		}
// 		clean_unique_data(data);
// 	}
// 	for(int i=0;data->labels[i];i++)
// 	{
// 		ft_printf("LBL [%s]\n", data->labels[i]);
// 	}
	
// 	return (1);
// }
int			handle_line(t_pack *data, char *line)
{
	int		i;
	int		flag;

	i = -1;
	flag = 0;
	while (line[++i] == ' ' || line[i] == '\t')
		;
	flag = valid_invalid_chars(data, line + i);
	if (flag == 1 || flag == -1) // increase data->lines only if line was with content, pay attention to the output
		data->l++;
	else if (!flag)
	{
		clean_the_line(data);
	}
	free(line);
	data->arg_len = 0;
	data->bytes += ft_strlen(line) + 1;
	return (flag);
}

int			begin(t_pack *data)
{
	char	*line;
	int		flag;
	int		i;

	data->bytes = 0;
	data->l++;
	i = -1;
	while (get_next_line(data->dsc, &line))
	{
		// ft_printf("LINE - %s\n", line);
		flag = handle_line(data, line);
	}
	for (int i = 0;data->cmnds[i];i++)
	{
		for(int j=0;data->cmnds[i][j];j++)
			ft_printf(" %s ", data->cmnds[i][j]);
		ft_printf("\n");
	}
	return (1);
}

int			label_exists(char *buf, t_pack *data)
{
	int		i;

	i = -1;
	while(data->labels[++i])
	{
		if (!ft_strcmp(buf, data->labels[i]))
			return (1);
	}
	data->labels[i] = ft_strdup(buf);
	return (1);
}

int			read_labels(t_pack *data, char *line)
{
	int		i;
	char	*buf;
	int		res;

	i = -1;
	buf = NULL;
	res = 0;
	while (line[++i] && 
        char_in_array(line[i]) &&
        line[i] != LABEL_CHAR)
			merge_chars(&buf, line[i]);
	if (i != -1 && line[i] == LABEL_CHAR)
	{
		merge_chars(&buf, line[i]);
		res = label_exists(buf, data);
		if (res)
			res = i + 1;
	}
	free(buf);
	return (res);
}

int			read_instructions(t_pack *data)
{
	char	*line;
	int		b;
	int		i;

	i = -1;
	while ((b = get_next_line(data->dsc, &line)))
	{
		read_labels(data, line);
		free(line);
		data->bytes += ft_strlen(line) + 1;
	}		
	lseek(data->dsc, -data->bytes, 1);
	begin(data);
	// delete_comments(data);
	// print_tokens(data);
	// actual_instructions(data);
	return (1);
}