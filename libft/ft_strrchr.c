/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qarcher <qarcher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 18:33:51 by qarcher           #+#    #+#             */
/*   Updated: 2015/01/22 13:11:03 by qarcher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		length;
	char	*tmp;

	tmp = (char *)s;
	length = ft_strlen(s);
	while (length >= 0)
	{
		if (s[length] == c)
			return (&tmp[length]);
		length = length - 1;
	}
	return (NULL);
}
