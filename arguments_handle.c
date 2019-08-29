/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments_handle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 11:17:48 by akorol            #+#    #+#             */
/*   Updated: 2019/07/25 11:17:54 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core_war.h"

int			direct_label(t_pack *data, char *line)
{
	int		i;
	char	*del;

	del = ft_strjoin(line, ":");
	i = -1;
	while (data->labels[++i])
	{
		if (!ft_strcmp(data->labels[i], del))
		{
			free(del);
			return (1);
		}
	}
	free(del);
	return (0);
}

int			indirect_validation(t_pack *data, char *line)
{
	char	*nbr;
	int		res;
	int		i;

	i = -1;
	res = 0;
	if (line && line[0] == ':' && direct_label(data, line + 1))
		return (1);
	else
	{
		while (line[++i])
		{
			if ((!ft_isdigit(line[i]) && line[i] != '-')
			|| (line[i] == '-' && i))
				return (0);
		}
		nbr = ft_strdup(line);
		res = ft_atoi(nbr) ? 1 : 0;
		free(nbr);
		return (res ? res : 0);
	}
}

int			indirect_arg(t_pack *data, char **line, int w)
{
	char	*nbr;
	int		i;

	i = -1;
	while (line[w][++i])
	{
		if (line[w][i] == '+')
			return (0);
	}
	nbr = ft_strsub(line[w], 0, i);
	i = ft_atoi(nbr);
	free(nbr);
	data = NULL;
	return (i);
}

int			register_check(char *line)
{
	int		i;
	int		res;
	int		flag;

	i = -1;
	if (line[++i] != 'r')
		return (0);
	flag = 0;
	while (line[++i])
	{
		if (!ft_isdigit(line[i]))
			return (0);
		flag = 1;
	}
	if (!flag)
		return (0);
	res = register_sti(line, i);
	return (res);
}

int			direct_number(t_pack *data, char **line, int w)
{
	int		i;
	char	*nbr;

	i = 0;
	if (!line[w][i + 1])
		return (0);
	while (line[w][++i])
	{
		if ((line[w][i] == '+' || (line[w][i] == '-' && i != 1)) ||
		(!ft_isdigit(line[w][i]) && line[w][i] != '+' && line[w][i] != '-'))
		{
			ft_printf("Error [%c]-idx-[%d]\n", line[w][i], i);
			return (0);
		}
	}
	nbr = ft_strsub(line[w], 0, i);
	free(nbr);
	data = NULL;
	return (1);
}
