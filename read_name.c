/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_name_comment.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 14:53:20 by akorol            #+#    #+#             */
/*   Updated: 2019/07/06 14:53:35 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core_war.h"

int			finish_name(t_pack *data, int count)	//check this name to be not bigger than PROG_NAME_LENGTH
{
	char	buf[count + 1];
	char	*del;
	int		bytes;

	del = data->name;
	data->name = ft_strjoin(data->name, "\n");
	free(del);
	if (data->name && (ft_strlen(data->name) + count - 1 > PROG_NAME_LENGTH))
		return (0);
	lseek(data->dsc, -count, 1);
	bytes = read(data->dsc, buf, count - 1);
	buf[bytes] = '\0';
	del = data->name;
	data->name = ft_strjoin(data->name, buf);
	free(del);
	bytes = read(data->dsc, buf, 1);
	buf[bytes] = '\0';
	return (1);
}

int         actual_name(t_pack *data, char *line)
{
    char    buf[BUF_SIZE + 1];
    int     bytes;
    int     count;
	int		i;

	i = -1;
    count = 0;
	while (line[++i] && line[i] != '"')
		;
	if (!data->name)
			data->name = ft_strsub(line, 0, i);
	if (line[i] == '"')
		return (check_after(line + i + 1));
    while ((bytes = read(data->dsc, buf, BUF_SIZE)))
    {
		count++;
		buf[bytes] = '\0';
		if (buf[0] == '"')
			return (finish_name(data, count));
    }
	return (0);
}

int         read_name(t_pack *data, char *line)
{
    int     i;
	int		res;
    
	if (data->name)
		return (0);
    i = -1;
    while (line[++i] && ((line[i] != '"' && (line[i] == ' ' || line[i] == '\t'))))
        ;
    if (line[i] && line[i] != '"')
	{
		ft_printf("Syntax error at token [TOKEN] ENDLINE\n");
        return (0);
	}
    if (!(res = actual_name(data, line + i + 1)))
	{
		ft_printf("Serious error at token [NAME]: wrong size!\n");
		return (0);
	}
    return (1);
}

int			check_file_name(t_pack *data, char *name)
{
	char	*pos;
	int		i;

	i = 0;
	pos = ft_strchr(name, '.');
	if (pos && pos[++i] == 's' && !pos[++i])
	{
		data->file_name = ft_strndup(name, pos - name);
		return (1);
	}
	else
	{
		ft_printf("Invalid file name [%s]\n", name);
		return (0);
	}
}