/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qarcher <qarcher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 19:18:32 by qarcher           #+#    #+#             */
/*   Updated: 2015/01/22 13:16:28 by qarcher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	int			length_s1;
	size_t		index;

	length_s1 = ft_strlen(s1);
	index = 0;
	while (index < n && s2[index] != '\0')
	{
		s1[length_s1] = s2[index];
		index = index + 1;
		length_s1 = length_s1 + 1;
	}
	s1[length_s1] = '\0';
	return (s1);
}
