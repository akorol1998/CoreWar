/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_comment.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 17:56:22 by akorol            #+#    #+#             */
/*   Updated: 2019/07/06 17:56:55 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core_war.h"

int			finish_comment(t_pack *data, int count)
{
	char	buf[count + 1];
	char	*del;
	int		bytes;

	del = data->comment;
	data->comment = ft_strjoin(data->comment, "\n");
	free(del);
	ft_printf("LENGTH - %d\n", ft_strlen(data->comment));
	if (data->comment && (ft_strlen(data->comment)
	+ count - 1 > COMMENT_LENGTH))
		return (0);
	lseek(data->dsc, -count, 1);
	bytes = read(data->dsc, buf, count - 1);
	buf[bytes] = '\0';
	del = data->comment;
	data->comment = ft_strjoin(data->comment, buf);
	free(del);
	bytes = read(data->dsc, buf, 1);
	buf[bytes] = '\0';
	return (1);
}

int			check_after(t_pack *da, char *line)
{
	int		i;

	i = -1;
	while (line[++i])
	{
		if (line[i] == '#')
			return (1);
		if (!(line[i] == ' ') && !(line[i] == '\t'))
		{
			ft_printf("Unknown symbols [%c]\n", line[i]);
			system("leaks asm");
			exit(EXIT_FAILURE);
		}
	}
	if (ft_strlen(da->comment) > COMMENT_LENGTH || ft_strlen(da->name)
	> PROG_NAME_LENGTH)
	{
		ft_printf("INAPROPRIATE COMMENT or NAME size\n");
		system("leaks asm");
		exit(EXIT_FAILURE);
	}
	return (1);
}

int			actual_comment(t_pack *data, char *line)
{
	char	buf[BUF_SIZE + 1];
	int		bytes;
	int		count;
	int		i;

	i = -1;
	count = 0;
	while (line[++i] && line[i] != '"')
		;
	if (!data->comment)
		data->comment = ft_strsub(line, 0, i);
	if (line[i] == '"')
		return (check_after(data, line + i + 1));
	while ((bytes = read(data->dsc, buf, BUF_SIZE)))
	{
		count++;
		buf[bytes] = '\0';
		if (buf[0] == '"')
			return (finish_comment(data, count));
	}
	return (0);
}

int			read_comment(t_pack *data, char *line)
{
	int		i;
	int		res;

	if (data->comment)
		return (0);
	i = -1;
	while (line[++i] && ((line[i] != '"'
	&& (line[i] == ' ' || line[i] == '\t'))))
		;
	if (line[i] && line[i] != '"')
	{
		ft_printf("Syntax error at token [TOKEN] ENDLINE\n");
		return (0);
	}
	if (!(res = actual_comment(data, line + i + 1)))
	{
		ft_printf("Serious error at token [COMMENT]: wrong size!\n");
		return (0);
	}
	return (1);
}
