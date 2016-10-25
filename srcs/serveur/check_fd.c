/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_fd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qarcher <qarcher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/20 17:10:31 by qarcher           #+#    #+#             */
/*   Updated: 2016/04/13 11:37:00 by qarcher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "server.h"

static void	check_server(t_env *env, int *ret)
{
	if (FD_ISSET(env->server_sock, &env->read_fd))
	{
		accept_server(env);
		(*ret)--;
	}
	if (FD_ISSET(0, &env->read_fd))
	{
		cmd_server(env);
		(*ret)--;
	}
}

void		check_fd(t_env *env, int ret)
{
	int		i;

	i = env->server_sock + 1;
	check_server(env, &ret);
	while ((i < env->max_fd_nbr) && ret > 0)
	{
		if (FD_ISSET(i, &env->write_fd))
		{
			manage_msg(i, env);
			ret--;
		}
		if (FD_ISSET(i, &env->read_fd))
		{
			read_client(i, env);
			ret--;
		}
		i++;
	}
}
