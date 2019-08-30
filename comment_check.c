/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comment_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 10:33:54 by akorol            #+#    #+#             */
/*   Updated: 2019/07/14 10:33:56 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core_war.h"

char		*delete_comments(char *line)
{
	char	*ptr;
	size_t	n;

	ptr = ft_strchr(line, '#');
	if (ptr)
	{
		n = ptr - line;
		ptr = ft_strndup(line, n);
	}
	else
		ptr = ft_strdup(line);
	return (ptr);
}

int			name_comment_block_2(int res)
{
	if (res)
		return (1);
	else
	{
		ft_printf("\033[1;31mSomething wrong with Name or Comment\033[0m\n");
		exit(EXIT_FAILURE);
		return (0);
	}
}

int			name_comment_block(t_pack *data)
{
	char	*line;
	int		c;
	int		res;

	c = 2;
	line = NULL;
	while (c--)
	{
		while (get_next_line(data->dsc, &line))
		{
			if (!search_dot(line))
			{
				break ;
			}
			free(line);
			line = NULL;
		}
		if (!(res = read_name_comment(data, line)))
			c = 0;
		free(line);
	}
	return (name_comment_block_2(res));
}
