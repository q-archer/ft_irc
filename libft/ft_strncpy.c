/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qarcher <qarcher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 17:50:15 by qarcher           #+#    #+#             */
/*   Updated: 2015/01/22 13:10:00 by qarcher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *s1, const char *s2, size_t n)
{
	size_t	index;
	size_t	length;

	length = ft_strlen(s2);
	index = 0;
	while (index < n)
	{
		if (index < length)
			s1[index] = s2[index];
		else
			s1[index] = '\0';
		index = index + 1;
	}
	return (s1);
}
