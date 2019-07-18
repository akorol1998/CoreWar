/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 10:34:22 by akorol            #+#    #+#             */
/*   Updated: 2019/07/14 10:34:53 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core_war.h"

int			op_bridge(t_pack *data, char *buf, int line, int w)
{
	int		res;

	data->line = line;
	data->w = w + 1;
	res = 0;
	if (!ft_strcmp(buf, "sti"))
	{
		ft_printf("Operation is {%s} - [%s]-data->buf[%s]\n", buf, data->tokens[line][w], data->buf);
		res = check_sti_op(data, line, w + 1);
	}
	else if (!ft_strcmp(buf, "live"))
	{
		ft_printf("Operation is {%s} - [%s]-data->buf[%s]\n", buf, data->tokens[line][w], data->buf);
		res = check_live_op(buf, data);
		
	}
	else if (!ft_strcmp(buf, "ld"))
	{
		ft_printf("Operation is {%s} - [%s]-data->buf[%s]\n", buf, data->tokens[line][w], data->buf);
		res = check_ld_op(data, buf);
	}
	free(data->buf);
	data->buf = NULL;
	ft_printf("Result = [%d]\n", res);
	return (res);
}

int			possible_ops(t_pack *data, char **buf, char *word, int i)
{
	int		n;
	char	*norm;

	n = -1;
	norm = NULL;
	while (compare_func(*buf, data)) //changed !
	{
		n = i;
		if (word[++i])
		{
			if (norm)
				free(norm);
			norm = ft_strdup(*buf);
			merge_chars(buf, word[i]);
		}
		else
			break ;
	}
	if (norm && !compare_func(*buf, data))
	{
		free((*buf));
		(*buf) = ft_strdup(norm);
	}
	free(norm);
	return (n != -1 ? n : 0);
}

int         check_for_being_op(t_pack *data, int line)
{
    int		i;
    char    *buf;

    buf = NULL;
	if(data->tokens[line])
	{
		i = -1;
		while (data->tokens[line][0] && data->tokens[line][0][++i])
		{
			merge_chars(&buf, data->tokens[line][0][i]);
            if (i + 1 >= 2 && i + 1 <= 5)
			{
				
				i = possible_ops(data, &buf, data->tokens[line][0], i);
				if (i)
                {
					ft_printf("Enter [%i] - op [%s]\n", i, buf);
					check_after_token(data, line, 0, i);
					op_bridge(data, buf, line, 0);
					ft_printf("Checking what is after operation in the element\n");
					free(buf);
                    return (1);
                }
				free(buf);
				return (0);
			}
		}
	}
	return (0);
}
