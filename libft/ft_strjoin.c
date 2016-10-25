/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qarcher <qarcher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 15:55:43 by qarcher           #+#    #+#             */
/*   Updated: 2015/03/03 16:53:33 by qarcher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	int		index;
	int		index_2;

	index = 0;
	index_2 = 0;
	if (!s1 || !s2)
		return (NULL);
	ret = (char *)malloc(sizeof(ret) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!ret)
		return (NULL);
	while (s1[index] != '\0')
	{
		ret[index] = s1[index];
		index = index + 1;
	}
	while (s2[index_2] != '\0')
	{
		ret[index] = s2[index_2];
		index = index + 1;
		index_2 = index_2 + 1;
	}
	ret[index] = '\0';
	return (ret);
}
