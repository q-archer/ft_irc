/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qarcher <qarcher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 15:28:03 by qarcher           #+#    #+#             */
/*   Updated: 2015/01/22 13:02:12 by qarcher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
	char	*tmp;
	char	*tmp_2;
	int		index;

	index = 0;
	tmp = (char *)s1;
	tmp_2 = (char *)s2;
	while (n > 0)
	{
		tmp[index] = tmp_2[index];
		index = index + 1;
		n = n - 1;
	}
	return (s1);
}
