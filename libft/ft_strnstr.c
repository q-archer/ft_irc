/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qarcher <qarcher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 19:06:22 by qarcher           #+#    #+#             */
/*   Updated: 2015/01/22 13:10:52 by qarcher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		j;
	size_t	tmp_i;
	size_t	tmp_j;

	i = 0;
	if (ft_strlen(s2) == 0)
		return ((char*)s1);
	while (s1[i] != '\0' && i != n)
	{
		j = 0;
		tmp_i = i;
		tmp_j = j;
		while (s2[j] != '\0' && tmp_i != n)
		{
			if (s1[tmp_i] == s2[tmp_j])
				tmp_j = tmp_j + 1;
			tmp_i = tmp_i + 1;
			if (tmp_j == ft_strlen(s2))
				return ((char*)&s1[i]);
			j = j + 1;
		}
		i = i + 1;
	}
	return (NULL);
}
