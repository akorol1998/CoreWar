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

int			validate_live_args(t_pack *data, char **tab)
{
	int		res;
	int		back;

	res = 0;
	if (data->arg1)
		res = 1;
	back = data->w;
	data->w = 0;
	if (!data->arg1)
	{
		if (tab[data->w] && tab[data->w][0] == '%')
		{	
			if (tab[data->w][1] == ':'
			&& direct_label(data, tab, 1, 2))
			{
				data->arg1 = 1;
				ft_printf("Direct label res\n");
			}
			else if (direct_number(data, tab, data->w))
			{
				data->arg1 = 1;
				ft_printf("Direct Number res\n");
			}
			else
				res = 0;
		}
	}
	else
		res = 1;
	if (res)
	{
		final_cut(data, tab);
	}
	data->w = back;
	return (res);
}

int			merge_live_arrays(t_pack *data, char **arr1, char **arr2)
{
	int		ln;
	int		j;
	int		i;
	char	**tab;

	ln = len_arr(arr1) + len_arr(arr2);
	tab = (char**)malloc(sizeof(char*) * ln + 1);
	tab[ln] = NULL;
	i = -1;
	while (arr1[++i])
		tab[i] = arr1[i];
	j = -1;
	while (arr2[++j])
		tab[j + i] = arr2[j];
	return (validate_live_args(data, tab));
}

void		clean_2d_arr(char **arr1)
{
	int		i;

	i = -1;
	while (arr1[++i])
		free(arr1[i]);
	free(arr1);
}

int			concatenate_live_buf(t_pack *data)
{
	char	**arr1;
	char	**arr2;
	char	*buf;
	char	*del;
	int		i;

	i = ++data->w;
	arr1 = ft_strsplit(data->buf, ',');
	buf = NULL;
	if (data->tokens[data->line][data->w])
	{
		buf = ft_strdup(data->tokens[data->line][data->w]);
		while (data->tokens[data->line][++i])
		{
			del = buf;
			buf = ft_strjoin(buf, data->tokens[data->line][i]);
			free(del);
		}
		arr2 = ft_strsplit(buf, ',');
		free(buf);
		ft_printf("(((((\n");
		i = merge_live_arrays(data, arr1, arr2);
		free(arr2);
		free(arr1);
	}
	else
	{
		if (ft_strcmp(arr1[0], ":"))
		{
			i = validate_live_args(data, arr1);
		}
		else
		{	
			clean_2d_arr(arr1);
			i = 0;
		}
	}
	return (i);
}


// {"live", 1, {T_DIR}, 1, 10, "alive", 0, 0}
// int			check_live_op(char *buf, t_pack *data)
// {
// 	char	*arg;

// 	if (!data->tokens[data->line][data->w])
// 	{
// 		if (data->buf)
// 		{
// 			ft_printf("Not present \n");
// 			arg = ft_strdup(data->buf);
// 			replace_line(buf, arg, data); //Check after token (operation)
// 			return (read_arg(data));
// 		}
// 		else
// 		{
// 			ft_printf("No argument!\n");
// 			return (0);
// 		}		
// 	}
// 	else
// 	{
// 		ft_printf("Element present [%s]-%p\n", data->tokens[data->line][data->w], data->tokens[data->line][data->w]);
// 		return (read_arg(data)); //Check after token (operation)
// 	}
// }

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
	ft_printf("Before\n");
	ft_printf("arg1 - 1[%d] arg2 - 2[%d] arg3 - 3[%d]\n", data->arg1, data->arg2, data->arg3);
	res = read_live_args(data, arr);
	ft_printf("After\n");
	ft_printf("arg1 - 1[%d] arg2 - 2[%d] arg3 - 3[%d]\n", data->arg1, data->arg2, data->arg3);
	fst = NULL;
	i = -1;
	while (arr[++i])
		free(arr[i]);
	free(arr);
	return (res);
}

// Current "live" operation function
int			check_op_live(t_pack *data, char *buf)
{
	int		res;

	res = 0;
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
		ft_printf("The current buffer - %s\n", data->buf);
		concatenate_live_buf(data);
		ft_printf("(((((\n");
	}
	else
	{
		structurize(data);
		res = 1;
	}
	return (res);
}