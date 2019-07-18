/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 12:39:08 by akorol            #+#    #+#             */
/*   Updated: 2019/07/18 12:39:19 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "core_war.h"

// char			**new_tab(char **line, int s)
// {
// 	int			i;
// 	int			j;
// 	char		**str;

// 	i = -1;
// 	while (++i < s)
// 		;
// 	str = (char**)malloc(sizeof(char*) * i + 1);
// 	str[i] = NULL;
// 	j = -1;
// 	while (++j < i)
// 		str[j] = ft_strdup(line[j]);
// 	return (str);
// }

// char			**new_tab2(char **line, int i)
// {
// 	char		*cley;
// 	char		**tab;
// 	char		*del;

// 	cley = ft_strdup(line[i]);
// 	while (line[++i])
// 	{
// 		del = cley;
// 		cley = ft_strjoin(del, line[i]);
// 		free(del);
// 	}
// 	tab = ft_strsplit(cley, ',');
// 	free(cley);
// 	return (tab);
// }
// void			clean_line_2(t_pack *data, char **tab, char **tab2)
// {
// 	int			i;
// 	int			j;
// 	int			ln2;
// 	int			ln;

// 	i = -1;
// 	while (data->tokens[data->line][++i])
// 		free(data->tokens[data->line][i]);
// 	free(data->tokens[data->line]);
// 	ln = len_arr(tab);
// 	ln2 = len_arr(tab2);
// 	data->tokens[data->line] = (char**)malloc(sizeof(char*) * (ln + ln2) + 1);
// 	data->tokens[data->line][ln + ln2] = NULL;
// 	i = -1;
// 	while (++i < ln + ln2)
// 		data->tokens[data->line][i] = tab[i];
// 	j = -1;
// 	while (i + ++j < ln + ln2)
// 		data->tokens[data->line][i + j] = tab2[j];
// }

// int				separate_arguments(t_pack *data)
// {
// 	int			i;
// 	int			j;
// 	char		**line;
// 	char		**tab;
// 	char		**tab2;

// 	i = -1;
// 	line = data->tokens[data->line];
// 	while (line[++i])
// 	{
// 		ft_printf("words - %s \n", line[i]);
// 		if (ft_strchr(line[i], ','))
// 			break ;
// 	}
// 	if (!line[i])
// 		return (0);
// 	tab = new_tab(line, i);
// 	tab2 = new_tab2(line, i);
// 	clean_line_2(data, tab, tab2);
// 	free(tab);
// 	free(tab2);
// 	j = 0;
// 	ft_printf("arg - %s\n", data->tokens[data->line][data->w]);
// 	system("leaks asm");
// 	exit(1);
// 	return (1);
// }

// // int				valid_data_buf(t_pack *data)
// // {
// // 	if (data->buf)
// // 	{
// // 		data
// // 	}
// // }