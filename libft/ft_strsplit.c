/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qarcher <qarcher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 18:44:29 by qarcher           #+#    #+#             */
/*   Updated: 2015/03/02 13:06:37 by qarcher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count_word(char const *s, char c)
{
	int			i;
	int			words;

	i = 0;
	words = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			words++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
		else
			i++;
	}
	return (words);
}

static int		ft_fill_mat(char ***split, char const *s, char c, int it_split)
{
	int			i;
	int			first;
	int			length;

	i = 0;
	first = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			length = 0;
			first = i;
			while (s[i] != c && s[i] != '\0')
			{
				length++;
				i++;
			}
			if (((*split)[it_split++] = ft_strsub(s, first, length)) == NULL)
				return (-1);
		}
		else
			i++;
	}
	(*split)[it_split] = NULL;
	return (0);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**split;
	int			it_split;
	int			words;

	it_split = 0;
	if (!s)
		return (NULL);
	words = ft_count_word(s, c);
	split = (char**)malloc(sizeof(char *) * (words + 1));
	if (!split)
		return (NULL);
	if (ft_fill_mat(&split, s, c, it_split) == -1)
		return (NULL);
	return (split);
}
