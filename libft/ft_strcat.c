/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qarcher <qarcher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 18:39:07 by qarcher           #+#    #+#             */
/*   Updated: 2015/01/22 13:09:10 by qarcher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	int		length_s1;
	int		length_s2;
	int		index;

	length_s1 = ft_strlen(s1);
	length_s2 = ft_strlen(s2);
	index = 0;
	while (index < length_s2)
	{
		s1[length_s1] = s2[index];
		index = index + 1;
		length_s1 = length_s1 + 1;
	}
	s1[length_s1] = '\0';
	return (s1);
}
