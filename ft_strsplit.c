/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrazzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 17:09:29 by mtrazzi           #+#    #+#             */
/*   Updated: 2017/05/27 18:03:49 by mtrazzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	int i;
	int n;

	n = 0;
	i = 0;
	while (s[i] && (s[i] == c))
		i++;
	while (s[i])
	{
		if (s[i] == c)
		{
			while (s[i] == c)
				i++;
			n++;
		}
		else
			i++;
	}
	return (n);
}

static	size_t	strlen_char(char const *s, char c)
{
	size_t i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	char	*tmp;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if ((tab = (char **)malloc(sizeof(char *) * count_words(s, c))) == NULL)
		return (0);
	while (j < count_words(s, c))
	{
		while (s[i] == c)
			i++;
		if ((tmp = ft_strnew(strlen_char(s + i, c))) == NULL)
			return (NULL);
		i--;
		while (s[++i] != c)
			tmp[i] = s[i];
		tab[j] = tmp;
		free(tmp);
		j++;
	}
	tab[j] = 0;
	return (tab);
}
