/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 12:57:19 by akorol            #+#    #+#             */
/*   Updated: 2019/07/17 12:57:29 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core_war.h"

//{"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load", 1, 0}
char 		**squeeze_elements(t_pack *data)
{
	int		i;
	char	**tab;

	i = -1;
	while (data->tokens[data->line][++i] && i <= data->w)
		;
	tab = (char **)malloc(sizeof(char *) * i + 1);
	tab[i] = NULL;
	i = -1;
	while (data->tokens[data->line][++i] && i <= data->w)
		tab[i] = ft_strdup(data->tokens[data->line][i]);
	return (tab);
}

void		replace_elements_in_line(t_pack *data, char **arr, char **arr2)
{
	int		i;
	int		j;
	int		len;
	int		len2;

	i = -1;
	while (data->tokens[data->line][++i])
		free(data->tokens[data->line][i]);
	free(data->tokens[data->line]);
	data->tokens[data->line] = NULL;
	len = len_arr(arr);
	len2 = len_arr(arr2);
	data->tokens[data->line] = (char**)malloc(sizeof(char*) * (len + len2) + 1);
	data->tokens[data->line][len + len2] = NULL;
	i = -1;
	while (++i < len)
		data->tokens[data->line][i] = arr[i];
	j = i;
	i = -1;
	while (++i + j < len + len2)
	{
		data->tokens[data->line][i + j] = arr2[i];
	}
	free(arr);
	free(arr2);
}	

int			replace_elements(t_pack *data, char *arg)
{
	char	*buf;
	char	**arr2;
	char	**arr;
	int		i;

	data->w--;
	buf = ft_strsub(data->tokens[data->line][data->w], 0, ft_strlen(arg));
	free(data->tokens[data->line][data->w]);
	data->tokens[data->line][data->w] = buf;
	i = data->w;
	while (data->tokens[data->line][++i])
	{
		if (data->buf)
		{
			buf = data->buf;
			data->buf = ft_strjoin(buf, data->tokens[data->line][i]);
			free(buf);
		}
		else
		{
			data->buf = ft_strdup(data->tokens[data->line][i]);
		}
	}
	arr2 = ft_strsplit(data->buf, ',');
	arr = squeeze_elements(data);
	replace_elements_in_line(data, arr, arr2);
	return (1);
}

int			check_indirect_arg(t_pack *data)
{
	ft_printf("Indirect argument [%s]\n", data->tokens[data->line][data->w]);
	data = NULL;
	return (1);
}

int			check_2nd_arg(t_pack *data, char **line)
{
	int		w;

	w = ++data->w;
	ft_printf(" LINE - %s\n", line[data->w]);
	if (line[w] && line[w][0] == 'r' && register_check(line, w))
		return (1);
	return (0);
}

int			read_ld_args(t_pack *data, char **line)
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
			res = check_2nd_arg(data, line);
			data->arg2 = res ? 1 : 0;
			ft_printf("Direct label res [%d]\n", res);
		}
		else if (direct_number(data, line, data->w))
		{
			data->arg1 = 1;
			res = check_2nd_arg(data, line);
			ft_printf("Direct Number res [%d]\n", res);
			data->arg2 = res ? 1 : 0;
		}
		else
			res = 0;
	}
	else if (indirect_validation(data, line, data->w))
	{
		data->arg1 = 1;
		res = check_2nd_arg(data, line);
		data->arg2 = res ? 1 : 0;
	}
	else
		res = 0;
	return (data->arg1 || data->arg2);
}

int			check_ld_op(t_pack *data, char *buf)
{
	int		res;

	//Function that counts ','
	res = 0;
	//custom functions
	if (!coma_count(data->tokens[data->line], 1))
	{
		ft_printf("Coma problems\n");
		system("leaks asm");
		exit(1);
	}
	if (data->buf)
	{
		res = buf_manager(data, buf);
		ft_printf("BUFFER\n");
		pick_word(data, "ld", data->line);
		concatenate_buf(data);
		ft_printf("(((((\n");
	}
	else
	{
		structurize(data);
		res = 1;
	}
	// system("leaks asm");
	// exit(1);
	ft_printf("))))\n");
	data->w = data->lbl ? 2 : 1;
	if (res)
	{
		res = read_ld_args(data, data->tokens[data->line]); // May not need this check, cause already have check in Buf_manager and concatenate_buf
	}
	ft_printf("Data->w %s\n", data->tokens[data->line][data->w + 1]);
	ft_printf("Hey = %d\n", res);	
	return (res);
}