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

int			direct_label(t_pack *data, char **line, int i, int s)
{
	char	*buf;
	char	*del;

	while (line[data->w][++i] && line[data->w][i] != '#')
		;
	del = ft_strsub(line[data->w], s, i - s);
	buf = ft_strjoin(del, ":");
	free(del);
	ft_printf("[[%s]]\n", buf);
	i = -1;
	while (data->labels[++i])
	{
		if (!ft_strcmp(data->labels[i], buf))
		{
			ft_printf("Direct Label [%s]\n", buf);
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
	int		res;
	int		flag;

	i = -1;
	if (line[w][++i] != 'r')
		return (0);
	flag = 0;
	while (line[w][++i])
	{
		if (!ft_isdigit(line[w][i]))
			return (0);
		flag = 1;
	}
	if (!flag)
		return (0);
	
	res = register_sti(line, w, i);
	return (res);
}

int			direct_number(t_pack *data, char **line, int w)
{
	int		i;
	char	*nbr;

	i = 0;
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
	ft_printf("Hello this is direct number [%s]\n", nbr);
	free(nbr);
	data = NULL;
	return (1);
}

int			next_argument(t_pack *data, char **line, int w)
{
	int		res;

	res = 0;
	data->w = w;
	if (!line[w])
		return (0);
	if (line[w][0] == 'r' && register_check(line, w)) //+
	{
		res = third_argument(data, line, data->w + 1);
	}
	else if (line[w][0] == '%')
	{
		if (line[w][1] == ':' && direct_label(data, line, 1, 2))
		{
			res = third_argument(data, line, data->w + 1);
		}
		else if (direct_number(data, line, w))
			res = third_argument(data, line, data->w + 1); //Check zerooooos and + sign
	}
	else if (indirect_validation(data, line, w)) // Doesn't "ft_isdigit(line[w][0])" work for negative numbers
		res = third_argument(data, line, data->w + 1);
		// if (ft_isdigit(line[w][0]), indirect_arg(data, line, data->w))
		// {
		// 	ft_printf("Indirect argument is valid :)\n");
		// 	res = third_argument(data, line, data->w + 1);
		// }
		// else if (direct_label(data, line, 0, 2))
		// 	res = third_argument(data, line, data->w + 1);
	// ft_printf("R - %d\n", res);
	return (res);
}
