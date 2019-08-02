/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 10:36:44 by akorol            #+#    #+#             */
/*   Updated: 2019/07/14 10:36:45 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core_war.h"

int			len_arr(char **arr)
{
	int		i;

	i = -1;
	while (arr[++i])
		;
	return (i);
}

int			compare_func(char *buf, t_pack *data)
{
	int		i;
	int		j;

	i = -1;
	j = ft_strlen(buf);
	while (data->op[++i])
	{
		if (!ft_strncmp(data->op[i], buf, j))
			return (1); // changed 0
	}
	return (0); // changed 1
}

int			count_comas_in_array(char *str, int n)
{
	int		i;
	int		count;

	count = 0;
	i = -1;
	while (str[++i])
	{
		if (str[i] == ',')
			count++;
	}
	return (count == n);
}

void		allocate_comm(t_pack *data)
{
	int		i;

	i = -1;
	data->comm = (t_cmnd**)malloc(sizeof(t_cmnd*) * CHAMP_MAX_SIZE + 1);
	while (++i <= CHAMP_MAX_SIZE)
		data->comm[i] = NULL;
}

int			check_commas(char *op, char *str)
{
	int		n;

	n = 0;
	if (!ft_strcmp(op, "live"))
		;
	else if (!ft_strcmp(op, "ld"))
		n = 1;
	else if (!ft_strcmp(op, "zjmp"))
		;
	else if (!ft_strcmp(op, "sti"))
		n = 2;
	else if (!ft_strcmp(op, "sub"))
		n = 2;
	else if (!ft_strcmp(op, "add"))
		n = 2;
	else if (!ft_strcmp(op, "and"))
		n = 2;
	else if (!ft_strcmp(op, "or"))
		n = 2;
	else if (!ft_strcmp(op, "xor"))
		n = 2;
	else if (!ft_strcmp(op, "ldi"))
		n = 2;
	else if (!ft_strcmp(op, "fork"))
		;
	else if (!ft_strcmp(op, "lld"))
		n = 1;
	else if (!ft_strcmp(op, "lldi"))
		n = 2;
	else if (!ft_strcmp(op, "lfork"))
		;
	else if (!ft_strcmp(op, "aff"))
		;
	else if (!ft_strcmp(op, "st"))
		n = 1;
	return (count_comas_in_array(str, n));
}