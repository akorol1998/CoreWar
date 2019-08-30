/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 15:07:11 by akorol            #+#    #+#             */
/*   Updated: 2019/07/05 15:08:35 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core_war.h"

int			read_name_comment(t_pack *data, char *line)
{
	int		i;

	i = -1;
	if (!line)
		return (0);
	while (line[++i] && (line[i] == ' ' || line[i] == '\t'))
		;
	if (!ft_strncmp(line + i, NAME_CMD_STRING, ft_strlen(NAME_CMD_STRING)))
	{
		if (!read_name(data, line + i + ft_strlen(NAME_CMD_STRING)))
			return (0);
	}
	else if (!ft_strncmp(line + i, COMMENT_CMD_STRING,
	ft_strlen(COMMENT_CMD_STRING)))
	{
		if (!read_comment(data, line + i + ft_strlen(COMMENT_CMD_STRING)))
			return (0);
	}
	else
	{
		ft_printf("\033[1;31mSyntax error"
		"at token [NAME or COMMENT]\033[0m\n");
		return (0);
	}
	return (1);
}

int			search_dot(char *line)
{
	int		i;

	i = -1;
	while (line[++i])
	{
		if (line[i] == '#')
			break ;
		else if (line[i] != ' ' && line[i] != '\t')
			return (0);
	}
	return (1);
}

void		start_reading(t_pack *data)
{
	int		nc;

	nc = name_comment_block(data);
	if (nc)
	{
		read_instructions(data);
	}
	else
	{
		ft_printf("\033[1;31mSomething went wrong :( \033[0m\n");
		exit(EXIT_FAILURE);
	}
	close(data->dsc);
}

int			main(int argc, char **argv)
{
	t_pack	*data;

	data = fill_data();
	if (argc != 2)
		return (0);
	if (!check_file_name(data, argv[1]))
		return (0);
	if ((data->dsc = open(argv[1], O_RDONLY)) == -1)
	{
		ft_printf("\033[1;31m%s \033[0m\n", strerror(EINVAL));
		return (0);
	}
	start_reading(data);
	writing_to_file(data);
	return (0);
}
