/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_break.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 16:18:28 by akorol            #+#    #+#             */
/*   Updated: 2019/01/09 15:41:59 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*add_break(char *line)
{
	char *buf;

	if (!line)
		return (NULL);
	buf = ft_strjoin(line, "\n");
	free(line);
	return (buf);
}
