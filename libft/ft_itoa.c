/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qarcher <qarcher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 17:35:10 by qarcher           #+#    #+#             */
/*   Updated: 2015/02/22 22:07:26 by qarcher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count_nbr(int n)
{
	int		i;
	int		div;

	i = 1;
	div = 1;
	if (n == -2147483648)
		return (11);
	if (n < 0)
		i = i + 1;
	while (n / div >= 10)
	{
		div = div * 10;
		i = i + 1;
	}
	return (i);
}

static char		*ft_norme(char *ret, int n)
{
	int		div;
	int		i;

	div = 1;
	i = 0;
	if (n < 0)
	{
		ret[i] = '-';
		i = i + 1;
		n = n * (-1);
	}
	while (n / div >= 10)
		div = div * 10;
	while (div > 0)
	{
		ret[i] = ((n / div) % 10) + '0';
		div = div / 10;
		i = i + 1;
	}
	ret[i] = '\0';
	return (ret);
}

char			*ft_itoa(int n)
{
	char	*ret;

	ret = (char *)malloc(sizeof(ret) * (ft_count_nbr(n) + 1));
	if (ret == NULL)
		return (NULL);
	if (n == -2147483648)
	{
		ret = ft_strdup("-2147483648");
		return (ret);
	}
	ret = ft_norme(ret, n);
	return (ret);
}
