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


// int			read_arg(t_pack *data)
// {
// 	int		res;

// 	res = 0;
// 	if (data->tokens[data->line][data->w][0] == '%')
// 	{
// 		if (data->tokens[data->line][data->w][1] == ':')
// 		{
// 			res = direct_label(data, data->tokens[data->line], 1, 2);
// 			ft_printf("Direct label res [%d]\n", res);
// 		}
// 		else
// 		{
// 			res = direct_number(data, data->tokens[data->line], data->w);
// 			ft_printf("Direct Number res [%d]\n", res);
// 		}
// 	}
// 	if (data->tokens[data->line][data->w + 1] && data->tokens[data->line][data->w + 1][0] != '#')
// 	{
// 		ft_printf("Excessive element !\n");
// 		return (0);
// 	}
// 	return (res);
// }

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
		ft_printf("Element present [%s]-%p\n", data->tokens[data->line][data->w], data->tokens[data->line][data->w]);
		return (read_arg(data)); //Check after token (operation)
	}
}

int			read_live_args(t_pack *data, char **line)
{
	int		res;

	res = 0;
	ft_printf("------%s\n", line[data->w]);
	if (line[data->w][0] == '%')
	{
		if (line[data->w][1] == ':'
		&& direct_label(data, line, 1, 2))
		{
			data->arg1 = 1;
			ft_printf("Direct label res [%d]\n", res);
		}
		else if (direct_number(data, line, data->w))
		{
			data->arg1 = 1;
			ft_printf("Direct Number res [%d]\n", res);
		}
		else
			res = 0;
	}
	return (data->arg1);
}			

int			buf_manager_live(t_pack *data, char *fst)
{
	char	**arr;
	int		res;
	int		i;

	arr = ft_strsplit(data->buf, ',');
	data->w = 0;
	//Custom function
	res = read_live_args(data, arr);
	ft_printf("arg1 - 1[%d] arg2 - 2[%d] arg3 - 3[%d]\n", data->arg1, data->arg2, data->arg3);
	fst = NULL;
	i = -1;
	while (arr[++i])
		free(arr[i]);
	free(arr);
	return (res);
}

int			check_op_live(t_pack *data, char *buf)
{
	if (!coma_count(data->tokens[data->line], 0))
	{
		ft_printf("Coma problems\n");
		system("leaks asm");
		exit(1);
	}
	if (data->buf)
	{
		//custom fucntion
		res = buf_manager_live(data, buf);
		ft_printf("BUFFER\n");
		pick_word(data, "live", data->line);
		concatenate_buf(data);
		ft_printf("(((((\n");
	}
	else
	{
		structurize(data);
		res = 1;
	}
}