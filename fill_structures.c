/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_structures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 13:21:32 by akorol            #+#    #+#             */
/*   Updated: 2019/07/06 13:21:50 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core_war.h"

t_pack		*fill_data(void)
{
	t_pack	*data;

	data = (t_pack*)malloc(sizeof(t_pack));
	data->tokens = NULL;
	data->labels = NULL;
	data->name = NULL;
	data->comment = NULL;
	data->op = NULL;
	data->dsc = 0;
	data->bytes = 0;
	return (data);
}
