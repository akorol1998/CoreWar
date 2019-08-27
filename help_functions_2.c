/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_functions_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 11:40:48 by akorol            #+#    #+#             */
/*   Updated: 2019/07/14 11:41:01 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core_war.h"

int			backwards(char *line)
{
	int		b;
	int		i;

	b = 1;
	if (line && (i = ft_strlen(line)))
	{
		while (i >= 0 && line[--i] && (line[i] == ' ' || line[i] == '\t'))
			;
		if (i >= 0 && line[i] != '\n')
			b = 0;
		free(line);
	}
	else
		b = 0;	
	return (b);
}

int			read_assm(t_pack *da)
{
	int		b;
	char	*line;
	char	*del;
	char	buf[BUF_SIZE + 1];

	b = 0;
	line = NULL;
	while ((b = read(da->dsc, buf, BUF_SIZE)))
	{
		buf[BUF_SIZE] = '\0';
		if (line)
		{
			del = line;
			line = ft_strjoin(del, buf);
			free(del);
		}
		else
			line = ft_strdup(buf);
	}
	return (backwards(line));
}

int			register_sti(char *line, int i)
{
	char	*nbr;
	int		j;

	j = -1;
	nbr = ft_strsub(line, 1, i - 1);
	while(nbr[++j])
	{
		if (nbr[j] == '+' || nbr[j] == '-')
			return (0);
	}
	if (j > 2 || ft_atoi(nbr) > 99 || ft_atoi(nbr) < 0 ||
	ft_atoi(nbr) > REG_NUMBER)
	{
		free(nbr);
		return (0);
	}
	free(nbr);
	return (1);
}

void		check_commas_2(char *op, int *n)
{
	if (!ft_strcmp(op, "ldi"))
		(*n) = 2;
	else if (!ft_strcmp(op, "fork"))
		;
	else if (!ft_strcmp(op, "lld"))
		(*n) = 1;
	else if (!ft_strcmp(op, "lldi"))
		(*n) = 2;
	else if (!ft_strcmp(op, "lfork"))
		;
	else if (!ft_strcmp(op, "aff"))
		;
	else if (!ft_strcmp(op, "st"))
		(*n) = 1;
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
	check_commas_2(op, &n);
	return (count_comas_in_array(str, n));
}
