/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qarcher <qarcher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 13:52:21 by qarcher           #+#    #+#             */
/*   Updated: 2015/03/03 16:45:21 by qarcher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dup;
	int		length;

	length = ft_strlen(s1);
	dup = (char *)malloc(sizeof(char) * (length + 1));
	if (dup)
	{
		length = 0;
		while (s1[length] != '\0')
		{
			dup[length] = s1[length];
			length = length + 1;
		}
		dup[length] = '\0';
		return (dup);
	}
	errno = ENOMEM;
	return (NULL);
}
