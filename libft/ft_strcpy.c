/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qarcher <qarcher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 12:12:52 by qarcher           #+#    #+#             */
/*   Updated: 2015/01/22 13:06:15 by qarcher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *s1, const char *s2)
{
	int		index;

	index = 0;
	while (s2[index] != '\0')
	{
		s1[index] = s2[index];
		index = index + 1;
	}
	s1[index] = '\0';
	return (s1);
}
