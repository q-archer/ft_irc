/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qarcher <qarcher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 20:08:56 by qarcher           #+#    #+#             */
/*   Updated: 2016/04/13 11:41:44 by qarcher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void		init_fd(t_env *env)
{
	FD_ZERO(&env->read_fd);
	FD_ZERO(&env->write_fd);
	FD_SET(env->socket, &env->read_fd);
	FD_SET(0, &env->read_fd);
	FD_SET(env->socket, &env->write_fd);
}
