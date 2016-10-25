/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qarcher <qarcher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 19:10:55 by qarcher           #+#    #+#             */
/*   Updated: 2015/01/22 13:12:55 by qarcher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int		i;
	int		j;
	int		tmp_i;
	size_t	tmp_j;

	i = 0;
	if (ft_strlen(s2) == 0)
		return ((char*)s1);
	while (s1[i] != '\0')
	{
		j = 0;
		tmp_i = i;
		tmp_j = j;
		while (s2[j] != '\0')
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
