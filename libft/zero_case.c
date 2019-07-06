/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zero_case.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 16:06:22 by akorol            #+#    #+#             */
/*   Updated: 2019/04/17 16:06:25 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*zero_case_precision(t_nigga **nig)
{
	char	*tmp;

	tmp = NULL;
	if (*(*nig)->conv == 'c')
		tmp = ft_strnew(1);
	else
	{
		if (!(*nig)->dot)
		{
			tmp = ft_strnew(1);
			fill2(tmp, 1);
		}
		else
		{
			tmp = ft_strnew((*nig)->p_s);
			fill2(tmp, (*nig)->p_s);
		}
		fill_wz_zero(tmp);
	}
	return (tmp);
}

void		zero_comb_func_2(char *final, int min, char *tmp, t_nigga **nig)
{
	if (!(*nig)->minus)
		custom_strcpy(final + min - ft_strlen(tmp), tmp);
	else
		custom_strcpy(final, tmp);
	last_piece(final, nig);
}

void		zeros_combine_funciton(char *tmp, t_nigga **nig)
{
	char	*final;
	int		min;

	final = NULL;
	min = (*nig)->m_s;
	if (min > (int)ft_strlen(tmp))
	{
		if (*(*nig)->conv == 'c')
			min--;
		final = ft_strnew(min);
		fill2(final, min);
		if ((*nig)->zero && !(*nig)->dot)
		{
			if ((*(*nig)->conv == 'c' && !(*nig)->minus) ||
				*(*nig)->conv != 'c')
				fill_wz_zero(final);
		}
		zero_comb_func_2(final, min, tmp, nig);
	}
	else
	{
		final = ft_strdup(tmp);
		last_piece(final, nig);
	}
}

void		zero_case_function(t_nigga **nig)
{
	char	*tmp;
	char	*zeros;
	char	*trash;

	zeros = NULL;
	trash = NULL;
	tmp = ft_strdup("0x");
	trash = tmp;
	zeros = zero_case_precision(nig);
	tmp = ft_strjoin(tmp, zeros);
	free(trash);
	free(zeros);
	zeros_combine_funciton(tmp, nig);
	if (tmp)
		free(tmp);
}

void		zero_case_pure_function(t_nigga **nig)
{
	char	*tmp;

	tmp = NULL;
	if (*(*nig)->conv == 'c')
		(*nig)->slashz++;
	tmp = zero_case_precision(nig);
	zeros_combine_funciton(tmp, nig);
	if (tmp)
		free(tmp);
}
