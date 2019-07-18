/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 10:12:05 by akorol            #+#    #+#             */
/*   Updated: 2019/07/17 10:12:23 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core_war.h"


int			read_arg(t_pack *data)
{
	int		res;

	res = 0;
	if (data->tokens[data->line][data->w][0] == '%')
	{
		if (data->tokens[data->line][data->w][1] == ':')
		{
			res = direct_label(data, data->tokens[data->line], 1, 2);
			ft_printf("Direct label res [%d]\n", res);
		}
		else
		{
			res = direct_number(data, data->tokens[data->line], data->w);
			ft_printf("Direct Number res [%d]\n", res);
		}
		
	}
	if (data->tokens[data->line][data->w + 1] && data->tokens[data->line][data->w + 1][0] != '#')
	{
		ft_printf("Excessive element !\n");
		return (0);
	}
	return (res);
}

int			replace_line(char *buf, char *arg, t_pack *data)
{
	int		i;

	i = -1;
	while (data->tokens[data->line][++i])
		free(data->tokens[data->line][i]);
	free(data->tokens[data->line]);
	data->tokens[data->line] = (char**)malloc(sizeof(char*) * 3);
	data->tokens[data->line][2] = NULL;
	data->tokens[data->line][0] = buf;
	data->tokens[data->line][1] = arg;
	ft_printf("First [%s]\n", data->tokens[data->line][0]);
	ft_printf("Second [%s]\n", data->tokens[data->line][1]);
	ft_printf("NULL [%s]\n", data->tokens[data->line][2]);
	return (1);
}

// {"live", 1, {T_DIR}, 1, 10, "alive", 0, 0}
int			check_live_op(char *buf, t_pack *data)
{
	char	*arg;

	if (!data->tokens[data->line][data->w])
	{
		if (data->buf)
		{
			ft_printf("Not present \n");
			arg = ft_strdup(data->buf);
			replace_line(buf, arg, data); //Check after token (operation)
			return (read_arg(data));
		}
		else
		{
			ft_printf("No argument!\n");
			return (0);
		}
		
	}
	else
	{
		ft_printf("Element present [%s]\n", data->tokens[data->line][data->w]);
		return (read_arg(data)); //Check after token (operation)
	}
}