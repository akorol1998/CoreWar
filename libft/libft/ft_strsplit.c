/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 13:07:52 by akorol            #+#    #+#             */
/*   Updated: 2018/11/25 13:29:18 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	count_words(char const *s, char c, size_t *times)
{
	while (*s != '\0')
	{
		while (*s == c)
			s++;
		if (*s != '\0')
			*times += 1;
		while (*s != c && *s != '\0')
			s++;
	}
	return (*times);
}

static	size_t	count_letters(char const *s, char c)
{
	int		i;
	size_t	letter;

	i = 0;
	letter = 0;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
		letter++;
	}
	return (letter);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**tab;
	size_t		words;
	size_t		k;
	size_t		p;

	k = -1;
	if (s == NULL)
		return (NULL);
	words = 0;
	if (!(p = count_words(s, c, &words)))
		return (NULL);
	tab = (char**)malloc(sizeof(char*) * p + 1);
	if (tab == NULL)
		return (NULL);
	while (++k < words)
	{
		while (*s == c && c != '\0')
			s++;
		tab[k] = ft_strsub(s, 0, count_letters(s, c));
		if (tab[k] == NULL)
			return (NULL);
		s += count_letters(s, c);
	}
	tab[k] = NULL;
	return (tab);
}
