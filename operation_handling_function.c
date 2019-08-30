/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_handling_function.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 12:20:04 by akorol            #+#    #+#             */
/*   Updated: 2019/08/29 12:20:05 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core_war.h"

int			check_line_tail(t_pack *data, char **arr)
{
	int		i;
	int		commment;

	i = -1;
	commment = 0;
	if (arr[data->arg_len] && arr[data->arg_len][0] != '#')
		return (0);
	return (1);
}

int			operation_valid_part_2(t_pack *data, char *op, char *str)
{
	int		res;
	int		i;
	char	**arr;

	res = 0;
	arr = coma_space_tab_split(str);
	free(str);
	res = choose_operation(data, op, arr);
	i = -1;
	if (arr)
	{
		while (arr[++i])
		{
			free(arr[i]);
		}
		free(arr);
	}
	return (res);
}

int			operation_valid(t_pack *data, char *op, char *line)
{
	char	*str;

	current_cmnds_position(data);
	data->cmnds[data->l][data->w] = ft_strdup(op);
	str = delete_comments(line + ft_strlen(op));
	if (!check_commas(op, str))
	{
		ft_printf("\033[1;31mEnd - %s\n", str);
		ft_printf("TOKEN ERROR operation - '%s'\nLINE - %s\033[0m\n", op, line);
		free(str);
		exit(EXIT_FAILURE);
	}
	if (str && str[0] != ' ' && str[0] != '\t'
	&& str[0] != '%' && str[0] != '-')
	{
		ft_printf("\033[1;31mInvalid symbols after '%s'"
		"- %c \033[0m\n", op, str[0]);
		exit(EXIT_FAILURE);
	}
	return (operation_valid_part_2(data, op, str));
}

int			handle_operation_part_2(t_pack *data, char *line, int *res)
{
	char	*op;
	int		i;

	i = -1;
	op = NULL;
	while (ft_strlen(op) < 2 && line && line[++i])
		merge_chars(&op, line[i]);
	i = possible_ops(data, &op, line, i);
	if (i)
		(*res) = operation_valid(data, op, line);
	else if (op && op[0] == '#')
		(*res) = 1;
	else
	{
		ft_printf("\033[1;31m Unknown command ahhhh [%s] \033[0m\n", op);
		exit(EXIT_FAILURE);
	}
	free(line);
	free(op);
	return (*res);
}

int			handle_operation(t_pack *data, char *str)
{
	int		i;
	char	*line;
	int		res;

	i = -1;
	res = 0;
	while (str && (str[++i] == ' ' || str[i] == '\t'))
		;
	line = ft_strdup(str + i);
	if (!ft_strlen(line))
	{
		free(line);
		return (-1);
	}
	return (handle_operation_part_2(data, line, &res));
}
