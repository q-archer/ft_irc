/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_mat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qarcher <qarcher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/08 13:56:25 by qarcher           #+#    #+#             */
/*   Updated: 2015/03/02 13:05:40 by qarcher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		**ft_strdup_mat(char **mat)
{
	int		size_mat;
	char	**ret;
	int		i;

	size_mat = ft_strlen_mat(mat);
	i = 0;
	ret = (char **)malloc(sizeof(char *) * (size_mat + 1));
	if (!ret)
		return (NULL);
	while (mat[i] != NULL)
	{
		ret[i] = ft_strdup(mat[i]);
		i++;
	}
	ret[i] = NULL;
	return (ret);
}
