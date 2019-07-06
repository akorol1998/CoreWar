/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 11:41:51 by akorol            #+#    #+#             */
/*   Updated: 2019/01/09 15:39:21 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 1

int					get_next_line(const int fd, char **line);
typedef	struct		s_node
{
	char			*data;
	int				ds;
	struct s_node	*next;
}					t_node;
#endif
