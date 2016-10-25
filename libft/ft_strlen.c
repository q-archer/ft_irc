/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qarcher <qarcher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 12:16:47 by qarcher           #+#    #+#             */
/*   Updated: 2015/03/03 16:38:42 by qarcher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlen(const	char *s)
{
	int		length;

	length = 0;
	while (s[length] != '\0')
	{
		length = length + 1;
	}
	return ((size_t)length);
}
