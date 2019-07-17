/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_index_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 10:35:40 by akorol            #+#    #+#             */
/*   Updated: 2019/07/14 10:36:31 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core_war.h"
// This fucntion will only work adter we handle all possible labels and then run the cycle again

int			sti_direct_label(t_pack *data, char **line, int i, int arg)
{
	char	*buf;

	arg = 1;
	while (line[data->w][++i] && line[data->w][i] != '#')
		;
	buf = ft_strsub(line[data->w], 2, i - 1);
	i = -1;
	while (data->labels[++i])
	{
		if (!ft_strcmp(data->labels[i], buf))
		{
			free(buf);
			return (1);
		}
	}
	free(buf);
	return (0);
}

int			register_check(char **line, int w)
{
	// char	*reg;
	// char	*nbr;
	int		i;
	int		flag;

	// reg = NULL;
	// merge_chars(&reg, line[w][1]);
	i = 0;
	flag = 0;
	while (line[w][++i])
	{
		if (!ft_isdigit(line[w][i]))
			return (0);
		flag = 1;
	}
	if (!flag)
		return (0);
	register_sti(line, w, i);
	return (1);
}

int			sti_direct_number(t_pack *data, char **line, int w, int arg)
{
	int		i;
	char	*nbr;

	ft_printf("Hello this is direct number [%s]\n", line[w]);
	i = 0;
	while (line[w][++i])
	{
		if ((line[w][i] == '+' || (line[w][i] == '-' && i != 1)) ||
		(!ft_isdigit(line[w][i])))
		{
			if (arg != 3 || line[w][i] != '#')
				return (0);
		}
	}	
	nbr = ft_strsub(line[w], 1, i);
	ft_printf("This is nbr [%s]\n", nbr);
	if (!ft_atoi(nbr))
	{
		free(nbr);
		return (0);
	}
	free(line[w]);
	line[w] = nbr;
	data = NULL;
	return (1);
}

int			third_argument(t_pack *data, char **line, int w)
{
	if (line[w][0] == 'r' && register_check(line, w))
		return (1);
	else if (line[w][0] == '%')
	{
		if (line[w][1] == ':' && sti_direct_label(data, line, w, 1))
			return (1);
		else if (sti_direct_number(data, line, w, 3))
			return (1);
		return (0);
	}
	return (0);
}

int			indirect_arg(t_pack *data, char **line, int w)
{
	char 	*nbr;
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

int			next_argument(t_pack *data, char **line, int w)
{
	int		res;

	res = 0;
	data->w = w;
	if (!line[w])
		return (0);
	if (line[w][0] == 'r' && register_check(line, w)) //+
		res = third_argument(data, line, data->w + 1);
	else if (line[w][0] == '%')
	{
		if (line[w][1] == ':' && sti_direct_label(data, line, 1, 2))
		{
			res = third_argument(data, line, data->w + 1);
		}
		else if (sti_direct_number(data, line, w, 2))
			res = third_argument(data, line, data->w + 1); //Check zerooooos and + sign
		return (res);
	}
	else if (ft_isdigit(line[w][0]) || line[w][0] == ':')
	{
		if (ft_isdigit(line[w][0]), indirect_arg(data, line, data->w))
		{
			res = third_argument(data, line, data->w + 1);
		}
		else if (sti_direct_label(data, line, 0, 2))
			res = third_argument(data, line, data->w + 1);
		return (res);
	}
	return (0);
}
