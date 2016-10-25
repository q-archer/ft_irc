/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qarcher <qarcher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 17:54:03 by qarcher           #+#    #+#             */
/*   Updated: 2015/01/22 15:35:26 by qarcher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	int				index;
	unsigned char	*tmp;

	index = 0;
	tmp = (unsigned char *)s;
	while (s && n > 0)
	{
		if (tmp[index] == (unsigned char)c)
			return (&tmp[index]);
		index = index + 1;
		n = n - 1;
	}
	return (NULL);
}
