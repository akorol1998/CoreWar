/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_tuner.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 17:16:34 by akorol            #+#    #+#             */
/*   Updated: 2019/03/18 17:16:37 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*condition_b_part_1(char *temp, t_nigga **nig)
{
	char	*trash;

	trash = NULL;
	if ((*nig)->plus == '+' && (*nig)->sign == '+')
	{
		trash = temp;
		temp = ft_strjoin("+", trash);
	}
	else if ((*nig)->sign == '-')
	{
		trash = temp;
		temp = ft_strjoin("-", trash);
	}
	if (trash)
		free(trash);
	return (temp);
}

char		*condition_b(char *digits, t_nigga **nig)
{
	char	*temp;
	char	*trash;

	trash = NULL;
	if (!ft_strcmp(digits, "0") && !(*nig)->p_s && !(*nig)->m_s && (*nig)->dot)
		temp = ft_strdup("");
	else
		temp = ft_strdup(digits);
	if ((*nig)->blank && (*nig)->plus != '+' && (*nig)->sign != '-')
	{
		trash = temp;
		temp = ft_strjoin(" ", trash);
		free(trash);
	}
	return (condition_b_part_1(temp, nig));
}
