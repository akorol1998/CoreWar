/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coma_space_tab_split.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 11:20:40 by akorol            #+#    #+#             */
/*   Updated: 2019/07/25 11:20:48 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	count_words(char const *s, size_t *times)
{
	while (*s != '\0')
	{
		while (*s == ' ' || *s == '\t' || *s == ',')
			s++;
		if (*s != '\0')
			*times += 1;
		while (*s != ' ' && *s != '\t' && *s != ',' && *s != '\0')
			s++;
	}
	return (*times);
}

static	size_t	count_letters(char const *s)
{
	int			i;
	size_t		letter;

	i = 0;
	letter = 0;
	while (s[i] != ' ' && s[i] != '\t' && s[i] != ',' && s[i] != '\0')
	{
		i++;
		letter++;
	}
	return (letter);
}

static	char	**create_arr(size_t *words, char const *s)
{
	int			p;
	int			i;
	char		**tab;

	if (!(p = count_words(s, words)))
		return (NULL);
	tab = (char**)malloc(sizeof(char*) * p + 1);
	i = -1;
	while (++i < p)
		tab[i] = NULL;
	if (tab == NULL)
		return (NULL);
	return (tab);
}

char			**coma_space_tab_split(char const *s)
{
	char		**tab;
	size_t		words;
	size_t		k;

	k = -1;
	if (s == NULL)
		return (NULL);
	words = 0;
	if (!(tab = create_arr(&words, s)))
		return (NULL);
	while (++k < words)
	{
		while ((*s == ' ' || *s == '\t' || *s == ',') && *s != '\0')
			s++;
		tab[k] = ft_strsub(s, 0, count_letters(s));
		if (tab[k] == NULL)
			return (NULL);
		s += count_letters(s);
	}
	tab[k] = NULL;
	return (tab);
}
