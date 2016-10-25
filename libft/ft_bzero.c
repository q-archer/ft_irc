/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qarcher <qarcher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 14:48:22 by qarcher           #+#    #+#             */
/*   Updated: 2015/01/22 12:56:55 by qarcher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	int		index;
	char	*tmp;

	index = 0;
	tmp = (char *)s;
	while (n > 0)
	{
		tmp[index] = '\0';
		index = index + 1;
		n = n - 1;
	}
}
