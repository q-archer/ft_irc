/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qarcher <qarcher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 19:18:10 by qarcher           #+#    #+#             */
/*   Updated: 2015/01/22 13:00:50 by qarcher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	size_t		index;
	char		*tmp_s2;
	char		*tmp_s1;

	index = 0;
	tmp_s2 = (char *)s2;
	tmp_s1 = (char *)s1;
	while (index != n)
	{
		tmp_s1[index] = tmp_s2[index];
		if (tmp_s2[index] == c)
		{
			index = index + 1;
			return (&tmp_s1[index]);
		}
		index = index + 1;
	}
	return (NULL);
}
