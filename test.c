/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 13:14:13 by akorol            #+#    #+#             */
/*   Updated: 2019/07/05 13:18:42 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "libft/ft_printf.h"
#include "op.h"

int			main(int argc, char **argv)
{
	int		dsc;
	int		size;
	int		i;
	int		a;
	char	*buf;
	char	*str = ft_strdup("Ba");

	str = realloc(str, ft_strlen(str));
	ft_printf("leng [%d]\n", ft_strlen(str));
	str[2] = '%';
	str[3] = '\0';
	ft_printf("[%s]\n", str);
	str = buf;
	system("leaks a.out");
	// dsc = open("binary.cor", O_WRONLY | O_CREAT);
	// printf("%d", dsc);
	
	// a = 0xea83f3;
	// size = 4;
	// while (size--)
	// {
	// 	i = a >> size * 8;
	// 	write(dsc, &i, 1);
	// }
	// i = -1;
	// while (++i < 6)
	// {
	// 	printf("%d[%c]\n", str[i], str[i]);	
	// 	write(dsc, &str[i], 1);
	// }
	return (0);
}