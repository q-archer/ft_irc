/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qarcher <qarcher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 13:11:48 by qarcher           #+#    #+#             */
/*   Updated: 2015/01/22 13:16:04 by qarcher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*mem;
	size_t	index;

	index = 0;
	mem = (void *)malloc(sizeof(mem) * size);
	if (mem)
	{
		while (index < size)
		{
			((char *)mem)[index] = 0;
			index = index + 1;
		}
		return (mem);
	}
	return (NULL);
}
