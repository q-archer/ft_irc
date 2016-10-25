/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qarcher <qarcher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 14:31:44 by qarcher           #+#    #+#             */
/*   Updated: 2015/01/22 13:08:52 by qarcher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	index;
	char			*ret;

	index = 0;
	if (s && f)
	{
		ret = (char *)malloc(sizeof(ret) * (ft_strlen(s) + 1));
		if (ret)
		{
			while (s[index] != '\0')
			{
				ret[index] = (*f)(index, s[index]);
				index = index + 1;
			}
			ret[index] = '\0';
			return (ret);
		}
	}
	return (NULL);
}
