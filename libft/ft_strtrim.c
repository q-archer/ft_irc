/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qarcher <qarcher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 17:48:48 by qarcher           #+#    #+#             */
/*   Updated: 2015/02/17 14:13:14 by qarcher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i_start;
	int		i_end;
	int		index;
	char	*ret;

	i_start = 0;
	index = 0;
	if (!s)
		return (NULL);
	i_end = ft_strlen(s) - 1;
	while (s[i_start] == ' ' || s[i_start] == '\t' || s[i_start] == '\n'
			|| s[i_start] == 10 || s[i_start] == '\f' || s[i_start] == '\r')
		i_start = i_start + 1;
	while (i_end > i_start && (s[i_end] == ' ' || s[i_end] == '\t'
			|| s[i_end] == '\n' || s[i_end] == '\v'
			|| s[i_end] == '\f' || s[i_end] == '\r'))
		i_end = i_end - 1;
	ret = (char *)malloc(sizeof(ret) * (i_end - i_start + 2));
	if (!ret)
		return (NULL);
	while (i_start <= i_end)
		ret[index++] = s[i_start++];
	ret[index] = '\0';
	return (ret);
}
