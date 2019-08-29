/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_handle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 10:39:11 by akorol            #+#    #+#             */
/*   Updated: 2019/07/25 10:39:19 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core_war.h"

int			possible_ops(t_pack *data, char **buf, char *word, int i)
{
	int		n;
	char	*norm;

	n = -1;
	norm = NULL;
	while (compare_func(*buf, data))
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

void		invalid_argumnet_exit(t_pack *data, char **arr, char *op)
{
	int		i;
	t_pack	*lol;

	i = -1;
	lol = data;
	if (arr)
	{
		while (arr[++i])
		{
			free(arr[i]);
		}
		free(arr);
	}
	ft_printf("TOKEN ERROR in '%s' operation.\n%s\n", op, strerror(EINVAL));
	system("leaks asm");
	exit(1);
}

int			choose_operation(t_pack *data, char *op, char **arr)
{
	int		res;

	res = 0;
	choose_operation_1(data, op, arr, &res);
	choose_operation_2(data, op, arr, &res);
	choose_operation_3(data, op, arr, &res);
	choose_operation_4(data, op, arr, &res);
	choose_operation_5(data, op, arr, &res);
	choose_operation_6(data, op, arr, &res);
	choose_operation_7(data, op, arr, &res);
	choose_operation_8(data, op, arr, &res);
	return (res);
}
