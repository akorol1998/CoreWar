/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writing_to_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 14:42:22 by akorol            #+#    #+#             */
/*   Updated: 2019/07/27 14:42:29 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core_war.h"

void		write_comment(t_pack *data)
{
	int		size;
	int		i;
	int		buf;

	size = ft_strlen(data->comment);
	buf = 0;
	i = -1;
	while (++i < size)
		write(data->dsc, &data->comment[i], 1);
	size = COMMENT_LENGTH - i;
	i = -1;
	while (++i < size)
		write(data->dsc, &buf, 1);
}

void		null_point_comment(t_pack *data)
{
	int		i;
	int		magic;

	i = -1;
	magic = 0;
	while (++i < 4)
		write(data->dsc, &magic, 1);
	data->pos = lseek(data->dsc, 0, 1); // Position for size of execution code
	i = -1;
	while (++i < 4)
		write(data->dsc, &magic, 1);
	write_comment(data);
	i = -1;
	while (++i < 4)
		write(data->dsc, &magic, 1);
}

void		magic_header_name(t_pack *data)
{
	int		size;
	int		magic;
	int		i;

	magic = COREWAR_EXEC_MAGIC;
	size = 4;
	while (size--)
	{
		i = magic >> size * 8;
		write(data->dsc, &i, 1);
	}
	size = ft_strlen(data->name);
	magic = 0;
	i = -1;
	while (++i < size)
		write(data->dsc, &data->name[i], 1);
	size = PROG_NAME_LENGTH - i;
	i = -1;
	while (++i < size)
		write(data->dsc, &magic, 1);
}
void		no_ops_check(t_pack *da)
{
	int		i;
	int		j;
	int		f;

	i = -1;
	f = 0;
	while (da->cmnds && da->cmnds[++i])
	{
		j = -1;
		while (da->cmnds[i][++j])
			f = 1;
	}
	if (!f)
	{
		ft_printf("NO OPERATIONS FOR THE CHAMPION!\n");
		system("leaks asm");
		exit(EXIT_FAILURE);
	}
}
int			writing_to_file(t_pack *data)
{
	int		res;
	char	*del;

	del = data->file_name;
	data->file_name = ft_strjoin(del, ".cor");
	free(del);
	no_ops_check(data);
	res = 0;
	if (!(data->dsc = open(data->file_name, O_WRONLY | O_CREAT | O_TRUNC)))
		return (0);
	magic_header_name(data);
	null_point_comment(data);
	execution_code(data);
	close(data->dsc);
	ft_printf("SUCCESS!\n");
	return (res);
}