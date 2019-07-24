/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_manipulation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 14:30:36 by akorol            #+#    #+#             */
/*   Updated: 2019/07/19 14:30:44 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core_war.h"

int		arrcnp(char	**arr1, char **arr2, int s)
{
	int		i;

	i = -1;
	if (!arr1 || !arr2)
		return (0);
	while (arr1[++i] && arr2[s])
	{
		arr1[i] = ft_strdup(arr2[s]);
		s++;
	}
	return (1);
}

int			new_line_func(t_pack *data, char *buf, int line)
{
	char	*fst;
	char	**arr1;
	char	**arr2;
	int		len;
	int		i;

	len = 0;
	fst = ft_strsub(data->tokens[line][0], 0,
	ft_strlen(data->tokens[line][0]) - ft_strlen(buf));
	arr1 = (char**)malloc(sizeof(char*) * 3);
	arr1[2] = NULL;
	arr1[0] = fst;
	arr1[1] = ft_strdup(buf);
	ft_printf(";;;;;;;; %s\n", buf);
	i = 1;
	while (data->tokens[line][i])
		i++;
	len = i - 1;
	ft_printf("Length = %d\n", len);
	arr2 = (char**)malloc(sizeof(char*) * len + 1);
	arr2[len] = NULL;
	if (arrcnp(arr2, data->tokens[line], 1))
	{
		for(int k = 0; arr1[k];k++)
			ft_printf("arr1 %s\n", arr1[k]);
		for(int k = 0; arr2[k];k++)
			ft_printf("arr2 %s\n", arr2[k]);
	}
	data->line = line;
	data->w = 1;
	replace_elements_in_line(data, arr1, arr2);
	for(int k = 0; data->tokens[line][k];k++)
			ft_printf("arr1 %s\n", data->tokens[line][k]);
	return (1);
}

void		insert_two_words(t_pack *data, char *buf, char* sub, int s)
{
	char	**pan;
	int		ln;
	int		i;
	int		j;

	pan = data->tokens[data->line];
	ln = len_arr(data->tokens[data->line]) + 1;
	data->tokens[data->line] = (char**)malloc(sizeof(char*) * ln + 1);
	data->tokens[data->line][ln] = NULL;
	i = -1;
	j = -1;
	while (++i < ln)
	{
		++j;
		if (i == s)
		{
			data->tokens[data->line][i] = ft_strdup(buf);	
			data->tokens[data->line][++i] = ft_strdup(sub);
		}
		else
			data->tokens[data->line][i] = ft_strdup(pan[j]);
	}
	i = -1;
	while (pan[++i])
		free(pan[i]);
	free(pan);
	// for(int y = 0; data->tokens[data->line][y];y++)
	// 	ft_printf("%s\n", data->tokens[data->line][y]);
}

int			extract_op(t_pack *data)
{
	int		i;
	int		leng;
	char	*buf;
	char	*sub;

	i = -1;
	buf = NULL;
					//data->op_idx;
	while (data->tokens[data->line][data->w][++i])
	{
		if (!(buf && (leng = ft_strlen(buf)) >= 2 && leng <= 5))
			merge_chars(&buf, data->tokens[data->line][data->w][i]);
		if ((leng = ft_strlen(buf)) >= 2 && leng <= 5)
		{
			ft_printf("op_idx is %d - [%s]\n", data->w, data->buf);
			i = possible_ops(data, &buf, data->tokens[data->line][data->w], i);
			if (!ft_strcmp(buf, data->tokens[data->line][data->w]))
			{
				ft_printf("clear - [%s]\n", data->tokens[data->line][data->w]);
				free(data->buf);
				data->buf = data->tokens[data->line][data->w + 1] ?
				ft_strdup(data->tokens[data->line][data->w + 1]) : NULL;
				ft_printf("joooofer - [%s]\n", data->buf);
				free(buf);
				return (1);
			}
			if (i)
			{
				sub = ft_strsub(data->tokens[data->line][data->w], ft_strlen(buf),
				ft_strlen(data->tokens[data->line][data->w]) - ft_strlen(buf));
				insert_two_words(data, buf, sub, 1);
				free(data->buf);
				data->buf = ft_strdup(sub);
				free(sub);
				free(buf);
				return (i);
			}
			system("leaks asm");
			ft_printf("LABEL WRONG [%s]\n", buf);
			free(buf);
			exit(1);
			return(0);
		}
	}
	free(buf);
	return (0);
}
