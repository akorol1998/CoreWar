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
	while (line[++i] && (line[i] == ' ' || line[i] == '\t'))
		;
	if (!ft_strncmp(line + i, NAME_CMD_STRING, ft_strlen(NAME_CMD_STRING)))
	{
		if (!read_name(data, line + i + ft_strlen(NAME_CMD_STRING)))
			return (0);
	}
	else if (!ft_strncmp(line + i, COMMENT_CMD_STRING, ft_strlen(COMMENT_CMD_STRING)))
	{
		if (!read_comment(data, line + i + ft_strlen(COMMENT_CMD_STRING)))
			return (0);
	}
	else
	{
		ft_printf("Syntax error at token [NAME or COMMENT]\n");
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
		if (line[i] != ' ' && line[i] != '\t')
		{
			ft_printf("symbol [%c][%d]", line[i], i);
			return (0);
		}
	}
	return (1);
}

// Didn't take into account the '#' symbols (normal comments) revamp this code to meet the criteria
void		start_reading(t_pack *data)
{
	char	*line;
	int		c;

	c = 2;
	line = NULL;
	while (c--)
	{
		while (get_next_line(data->dsc, &line))
		{
			if (!search_dot(line))
				break;
			free(line);
		}
		if (!read_name_comment(data, line))
			c = 0;
		free(line);
	}
	system("leaks asm");
	ft_printf("Name [%s]\n", data->name);
	ft_printf("Comment [%s]\n", data->comment);
}

int			main(int argc, char **argv)
{
	int		dsc;
	t_pack	*data;
	
	if (argc != 2)
		return (0);
	if ((dsc = open(argv[1], O_RDONLY)) == -1)
	{
		ft_printf("%s\n", strerror(EINVAL));
		return (0);
	}
	ft_printf("%d", dsc);
	data = fill_data();
	data->dsc = dsc;
	start_reading(data);
	return (0);
}
