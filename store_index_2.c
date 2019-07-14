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

int			sti_direct_label(t_pack *data, char **line, int w)
{
	int		i;
	char	*buf;

	i = 1;
	while (line[w][++i])
		;
	buf = ft_strsub(line[w], 2, i - 1);
	ft_printf("Label: {%s}\n", buf);
	i = -1;
	while (data->labels[++i])
	{
		if (!ft_strcmp(data->labels[i], buf))
		{
			ft_printf("{%s}\n", line[w]);
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

int			next_argument(t_pack *data, char **line, int w)
{
	if (!line[w])
		return (0);
	if (line[w][0] == 'r' && register_check(line, w))
		ft_printf("check 3d argumnet");
	else if (line[w][0] == '%')
	{
		if (line[w][1] == ':' && sti_direct_label(data, line, w))
			ft_printf("Direct label\n"); // process this case
		if (ft_isdigit(line[w][1]))
			ft_printf("Direct number\n"); //Check zerooooos and + sign
	}
	return (1);
}
