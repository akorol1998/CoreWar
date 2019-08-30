/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_handle_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 13:48:32 by akorol            #+#    #+#             */
/*   Updated: 2019/07/25 13:48:57 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core_war.h"

int			is_operation(t_pack *data, char *line)
{
	int		i;
	int		res;
	char	*op;

	i = -1;
	op = NULL;
	while (ft_strlen(op) < 2 && line && line[++i])
		merge_chars(&op, line[i]);
	if (op)
	{
		i = possible_ops(data, &op, line, i);
	}
	if (i)
	{
		res = operation_valid(data, op, line);
	}
	else
		res = 0;
	free(op);
	return (res);
}

int			comment_case(char *line, int i)
{
	int		j;

	j = 0;
	while (line[--i] && line[i] != '\n')
		;
	while (line[++i] && (line[i] == ' ' || line[i] == '\t'))
		;
	if (line[i] == '#')
		return (1);
	return (0);
}
