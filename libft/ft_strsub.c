/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qarcher <qarcher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 15:32:00 by qarcher           #+#    #+#             */
/*   Updated: 2015/02/10 20:12:33 by qarcher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*ret;
	unsigned int	index;

	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (s && ret)
	{
		index = 0;
		while (index < len)
		{
			ret[index] = s[start];
			start = start + 1;
			index = index + 1;
		}
		ret[index] = '\0';
		return (ret);
	}
	return (NULL);
}
