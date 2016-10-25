/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_server.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qarcher <qarcher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 17:44:21 by qarcher           #+#    #+#             */
/*   Updated: 2016/04/13 12:10:48 by qarcher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "server.h"

void		error_server(t_env *env, char *e)
{
	int		i;

	i = 0;
	if (env)
	{
		ft_error(env->bin, e);
		free_env(env);
	}
	exit(-1);
}
