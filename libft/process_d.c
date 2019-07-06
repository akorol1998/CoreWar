/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 12:01:49 by akorol            #+#    #+#             */
/*   Updated: 2019/02/15 12:02:03 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*condition_a_part_1(t_nigga **nig)
{
	char	*temp;
	char	*trash;

	temp = ft_strnew((*nig)->p_s);
	fill2(temp, (*nig)->p_s);
	fill_wz_zero(temp);
	if ((*nig)->blank && (*nig)->plus != '+' && (*nig)->sign != '-')
	{
		trash = temp;
		temp = ft_strjoin(" ", trash);
		free(trash);
	}
	else if ((*nig)->plus == '+' && (*nig)->sign == '+')
	{
		trash = temp;
		temp = ft_strjoin("+", trash);
		free(trash);
	}
	else if ((*nig)->sign == '-')
	{
		trash = temp;
		temp = ft_strjoin("-", trash);
		free(trash);
	}
	return (temp);
}

char	*condition_a_part_2(t_nigga **nig)
{
	char	*temp;

	temp = ft_strnew((*nig)->m_s);
	fill2(temp, (*nig)->m_s);
	fill_wz_zero(temp);
	if ((*nig)->plus == '+' && (*nig)->sign == '+')
		temp[0] = '+';
	else if ((*nig)->sign == '-')
		temp[0] = '-';
	else if ((*nig)->blank)
		temp[0] = ' ';
	return (temp);
}

char	*condition_a_part_3(char *digits, t_nigga **nig)
{
	char	*temp;
	char	*trash;

	temp = ft_strdup(digits);
	if ((*nig)->plus == '+' && (*nig)->sign == '+')
	{
		trash = temp;
		temp = ft_strjoin("+", trash);
		free(trash);
	}
	else if ((*nig)->sign == '-')
	{
		trash = temp;
		temp = ft_strjoin("-", trash);
		free(trash);
	}
	else if ((*nig)->blank)
	{
		trash = temp;
		temp = ft_strjoin(" ", trash);
		free(trash);
	}
	return (temp);
}

char	*condition_a(int g, int len, char *digits, t_nigga **nig)
{
	char	*temp;
	char	*box;

	if ((*nig)->p_s > len)
	{
		temp = condition_a_part_1(nig);
		custom_strcpy(temp + ft_strlen(temp) - ft_strlen(digits), digits);
	}
	else if ((*nig)->zero && !(*nig)->p_s && (*nig)->minus != '-')
	{
		temp = condition_a_part_2(nig);
		custom_strcpy(temp + ft_strlen(temp) - ft_strlen(digits), digits);
	}
	else
		temp = condition_a_part_3(digits, nig);
	g = (int)ft_strlen(temp) > g ? (int)ft_strlen(temp) : g;
	box = ft_strnew(g);
	fill2(box, g);
	if ((*nig)->minus)
		custom_strcpy(box, temp);
	else
		custom_strcpy(box + g - ft_strlen(temp), temp);
	free(temp);
	return (box);
}
