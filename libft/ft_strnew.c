/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qarcher <qarcher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 11:36:01 by qarcher           #+#    #+#             */
/*   Updated: 2015/01/22 13:10:34 by qarcher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;
	size_t	index;

	index = 0;
	str = (char *)malloc(sizeof(str) * (size + 1));
	if (str)
	{
		while (index <= size)
		{
			str[index] = '\0';
			index = index + 1;
		}
		return (str);
	}
	return (NULL);
}
