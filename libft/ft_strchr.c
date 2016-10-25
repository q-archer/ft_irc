/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qarcher <qarcher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 18:20:41 by qarcher           #+#    #+#             */
/*   Updated: 2015/01/22 13:05:51 by qarcher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		index;
	int		length;
	char	*tmp;

	tmp = (char *)s;
	length = ft_strlen(s);
	index = 0;
	while (length >= 0)
	{
		if (s[index] == c)
			return (&tmp[index]);
		index = index + 1;
		length = length - 1;
	}
	return (NULL);
}
