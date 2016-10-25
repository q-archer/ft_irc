/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qarcher <qarcher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 14:56:07 by qarcher           #+#    #+#             */
/*   Updated: 2013/11/25 15:55:45 by qarcher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		n;
	size_t		length_dst;
	size_t		length_src;
	size_t		tmp_length;
	int			index;

	n = size - ft_strlen(dst) - 1;
	length_dst = ft_strlen(dst);
	length_src = ft_strlen(src);
	tmp_length = length_dst;
	index = 0;
	if (size <= length_dst)
		return (length_src + size);
	while (n != 0)
	{
		dst[length_dst] = src[index];
		n = n - 1;
		length_dst = length_dst + 1;
		index = index + 1;
	}
	dst[length_dst] = '\0';
	return (length_src + tmp_length);
}
