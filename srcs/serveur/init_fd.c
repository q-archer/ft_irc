/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qarcher <qarcher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/20 15:40:45 by qarcher           #+#    #+#             */
/*   Updated: 2016/04/13 11:38:59 by qarcher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void		init_fd(t_env *env)
{
	int		i;

	i = env->server_sock + 1;
	FD_ZERO(&env->read_fd);
	FD_ZERO(&env->write_fd);
	FD_SET(env->server_sock, &env->read_fd);
	FD_SET(0, &env->read_fd);
	while (i < env->max_fd_nbr)
	{
		if (env->all_fd[i].set == 1)
		{
			FD_SET(i, &env->read_fd);
			if (env->all_fd[i].empty_write != 1)
				FD_SET(i, &env->write_fd);
		}
		i++;
	}
}
