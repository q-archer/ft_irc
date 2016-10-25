/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_fd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qarcher <qarcher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 20:13:11 by qarcher           #+#    #+#             */
/*   Updated: 2016/04/13 11:41:33 by qarcher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "client.h"

void		check_fd(t_env *env)
{
	if (FD_ISSET(env->socket, &env->write_fd))
	{
		if (env->buf_write[0] != '\0')
			write_client(env, 0);
	}
	if (FD_ISSET(env->socket, &env->read_fd))
		read_client(env);
	if (FD_ISSET(0, &env->read_fd))
		write_client(env, 1);
}
