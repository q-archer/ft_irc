/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qarcher <qarcher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 15:32:10 by qarcher           #+#    #+#             */
/*   Updated: 2013/11/24 18:49:27 by qarcher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		index;
	int		n;
	int		sign;

	index = 0;
	n = 0;
	sign = 1;
	while ((str[index] >= 9 && str[index] <= 13) || str[index] == ' ')
		index = index + 1;
	if (str[index] == '+')
		index = index + 1;
	else if (str[index] == '-')
	{
		sign = -1;
		index = index + 1;
	}
	while (ft_isdigit(str[index]) != 0)
	{
		n = n * 10 + str[index] - 48;
		index = index + 1;
	}
	return (n * sign);
}
