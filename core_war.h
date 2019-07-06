/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_war.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 15:08:45 by akorol            #+#    #+#             */
/*   Updated: 2019/07/05 15:10:28 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORE_WAR_H
# define CORE_WAR_H
# include "libft/ft_printf.h"
# include "errno.h"
# include "fcntl.h"
# include "op.h"
# define BUF_SIZE 1
typedef struct      s_pack
{
    char            ***tokens;
    char            **labels;
    char            **op;
    char            *name;
    char            *comment;
    int             dsc;
	int				bytes;
}                   t_pack;

t_pack	        	*fill_data(void);
int                 read_name(t_pack *data, char *line);
int			         read_comment(t_pack *data, char *line);

#endif