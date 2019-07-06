/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 17:05:50 by akorol            #+#    #+#             */
/*   Updated: 2019/02/12 14:02:48 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ending_output(char *main, va_list args, t_nigga *nig)
{
	t_nigga		*node;
	int			slashz;
	int			i;

	ft_putstr(main);
	slashz = 0;
	while (nig)
	{
		node = nig;
		slashz += node->slashz;
		nig = nig->next;
		free(node);
	}
	va_end(args);
	free(main);
	i = main ? ft_strlen(main) + slashz : 0;
	return (i);
}

int				concatenating(t_nigga *nig, va_list args)
{
	char		*main;
	char		*trash;
	t_nigga		*node;

	node = nig;
	main = NULL;
	while (node)
	{
		if (main && node->out)
		{
			trash = main;
			main = ft_strjoin(main, node->out);
			free(trash);
		}
		else if (node->out)
			main = ft_strdup(node->out);
		if (node->out)
			free(node->out);
		node = node->next;
	}
	return (ending_output(main, args, nig));
}

int				pick_up_args(va_list args, char const *fmt, t_nigga **lopata)
{
	char const	*point;
	char const	*loc;
	t_nigga		*head;

	point = ft_strdup(fmt);
	loc = point;
	head = (*lopata);
	while (*loc)
	{
		loc = customize_string(loc, lopata);
		if (*loc)
			loc++;
		customize_flags(loc, lopata);
		if ((*lopata)->conv)
			tuner(&loc, lopata, args);
	}
	free((void *)point);
	return (concatenating(head, args));
}

int				ft_printf(const char *restrict fmt, ...)
{
	va_list		args;
	t_nigga		*nig;

	nig = NULL;
	fill_my_nigga(&nig);
	va_start(args, fmt);
	return (pick_up_args(args, fmt, &nig));
}
