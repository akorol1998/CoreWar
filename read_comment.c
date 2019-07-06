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

int			finish_comment(t_pack *data, int count)	//check this name to be not bigger than PROG_NAME_LENGTH
{
	char	buf[count + 1];
	char	*del;
	int		bytes;

	del = data->comment;
	data->comment = ft_strjoin(data->comment, "\n");
	free(del);
	if (data->comment && (ft_strlen(data->comment) + count - 1 > COMMENT_LENGTH))
		return (0);
	lseek(data->dsc, -count, 1);
	bytes = read(data->dsc, buf, count - 1);
	buf[bytes] = '\0';
	ft_printf(" name bitch [%s]\n", buf);
	del = data->comment;
	data->comment = ft_strjoin(data->comment, buf);
	free(del);
	bytes = read(data->dsc, buf, 1);
	buf[bytes] = '\0';
	return (1);
}

int         actual_comment(t_pack *data, char *line)
{
    char    buf[BUF_SIZE + 1];
    int     bytes;
    int     count;
	int		i;

	i = -1;
    count = 0;
	while (line[++i] && line[i] != '"')
		;
	if (!data->comment)
			data->comment = ft_strsub(line, 0, i);
	if (line[i] == '"')
		return (1);
	ft_printf("Hey [%s]\n", data->name);
    while ((bytes = read(data->dsc, buf, BUF_SIZE)))
    {
		count++;
		buf[bytes] = '\0';
		if (buf[0] == '"')
			return (finish_comment(data, count));
    }
	return (0);
}

int         read_comment(t_pack *data, char *line)
{
    int     i;
	int		res;
	
    if (data->comment)
		return (0);
    ft_printf("|%s|\n", line);
    i = -1;
    while (line[++i] && ((line[i] != '"' && (line[i] == ' ' || line[i] == '\t'))))
        ;
    if (line[i] && line[i] != '"')
        return (0);
	ft_printf("|%s|\n", line + i);
    if (!(res = actual_comment(data, line + i + 1)))
		ft_printf("Serious error at token [NAME]: wrong size!\n");
	else
		ft_printf("== %s ==", data->comment);
    return (1);
}