/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qarcher <qarcher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 17:35:46 by qarcher           #+#    #+#             */
/*   Updated: 2015/01/22 16:44:00 by qarcher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int		index;
	char	*ts1;
	char	*ts2;

	ts1 = (char *)s1;
	ts2 = (char *)s2;
	if (!s1 || !s2)
		return (0);
	index = 0;
	while (n > 0)
	{
		if (ts1[index] != ts2[index])
			return ((unsigned char)ts1[index] - (unsigned char)ts2[index]);
		index = index + 1;
		n = n - 1;
	}
	return (0);
}
