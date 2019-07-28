/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_code_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 16:17:48 by akorol            #+#    #+#             */
/*   Updated: 2019/07/28 16:17:57 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core_war.h"

// void			pick_op_for_processing(t_pack *da, int w, int *idx)
// {
// 	(*idx)++;
// 	if (!ft_strcmp(da->cmnds[da->l][w], "sti"))
// 		sti_op_size(da, w);
// 	if (!ft_strcmp(da->cmnds[da->l][w], "and"))
// 		and_op_size(da, w);
// }

// void			go_through_ops(t_pack *da)
// {
// 	int			i;
// 	int			j;
// 	int			k;

// 	da->l = -1;
// 	k = -1;
// 	while (da->cmnds[++da->l])
// 	{
// 		da->w = -1;
// 		while (da->cmnds[da->l][++da->w])
// 		{
// 			if (!da->w && compare_func(da->cmnds[da->l][da->w], da))
// 				pick_op_for_processing(da, da->w, &k);
// 			else if (!da->w && da->cmnds[da->l][da->w + 1] &&
// 			compare_func(da->cmnds[da->l][da->w + 1], da))
// 				pick_op_for_processing(da, da->w + 1, &k);
// 		}
// 	}
// }