/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qarcher <qarcher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 12:25:15 by qarcher           #+#    #+#             */
/*   Updated: 2015/01/22 12:57:43 by qarcher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isalnum(int c)
{
	int		test_alpha;
	int		test_digit;

	test_alpha = ft_isalpha(c);
	test_digit = ft_isdigit(c);
	if (test_alpha != 0 || test_digit != 0)
		return (1);
	else
		return (0);
}
